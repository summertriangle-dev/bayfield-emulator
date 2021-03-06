#include <stdlib.h>
#include <string.h>
#include "emucore.h"
#include "emucore_internal.h"
#include "insn.h"

#define CLOCKS_PER_SEC 4194304
#define CLOCKS_PER_MACH 4

#if SIMULATE_PIPELINE
uint64_t n_instructions;
uint64_t n_fetch_fails;
#endif

static uint8_t cpu_user_get_irqs(bc_cpu_t *cpu, void *context, uint16_t addr, uint8_t saved_val) {
    return cpu->irqs;
}

static uint8_t cpu_user_set_irqs(bc_cpu_t *cpu, void *context, uint16_t addr, uint8_t write_val) {
    cpu->irqs = write_val;
    return 0;
}

bc_cpu_t *bc_cpu_init(void) {
    bc_cpu_t *ret = malloc(sizeof(bc_cpu_t));
    memset(ret, 0, sizeof(bc_cpu_t));
    bc_mmap_alloc(&ret->mem);
    ret->mem.cpu = ret;

    bc_mmap_add_mmio_observer(&ret->mem, 0xFF0F, cpu_user_set_irqs, cpu_user_get_irqs, NULL);
    bc_mmap_add_mmio_observer(&ret->mem, 0xFF04, cpu_user_set_div, cpu_user_get_div, NULL);
    bc_mmap_add_mmio_observer(&ret->mem, 0xFF05, cpu_user_set_tima, cpu_user_get_tima, NULL);
    bc_mmap_add_mmio_observer(&ret->mem, 0xFF06, NULL, NULL, NULL);
    bc_mmap_add_mmio_observer(&ret->mem, 0xFF07, cpu_user_set_tac, NULL, NULL);

    return ret;
}

void bc_request_interrupt(bc_cpu_t *cpu, enum bc_int_flag interrupt) {
    interrupt &= 0x1f;
    cpu->irqs |= interrupt;
} 

static int goto_isr_if_allowed(bc_cpu_t *cpu, int active, enum bc_int_flag flg, uint16_t sr_address) {
    if (active & flg) {
        cpu->irqs &= (~flg);
        // moving PC to isr takes 20 clocks/5 machs
        bc_cpu_stall(cpu, 20, STALL_TYPE_BACK);
        // disable further interrupts
        cpu->irq_mask &= ~IF_MASTER;
        // push pc onto stack and go to ISR
        bc_mmap_putstack16(&cpu->mem, cpu->regs.PC);
        debug_log("PC -> %x for ISR", sr_address);
        cpu->regs.PC = sr_address;
        return 1;
    }
    return 0;
}

static int do_interrupts(bc_cpu_t *cpu) {
    if (!(cpu->irq_mask & IF_MASTER)) {
        if (cpu->irqs) {
            if (cpu->halt) {
                debug_log("arise, game boy");
            }
            cpu->halt = 0;
        }
        // debug_log("interrupts disabled - doing nothing!");
        return 0;
    }

    int real_irqs = cpu->irqs & cpu->irq_mask;
    if (real_irqs) {
        if (cpu->halt) {
            debug_log("arise, game boy, and go isr");
        }
        cpu->halt = 0;
    }

    if (goto_isr_if_allowed(cpu, real_irqs, IF_VBLANK, ISR_VBLANK)) return 1;
    if (goto_isr_if_allowed(cpu, real_irqs, IF_LCDSTAT, ISR_LCDSTAT)) return 1;
    if (goto_isr_if_allowed(cpu, real_irqs, IF_TIMER, ISR_TIMER)) return 1;
    if (goto_isr_if_allowed(cpu, real_irqs, IF_SERIAL, ISR_SERIAL)) return 1; 
    if (goto_isr_if_allowed(cpu, real_irqs, IF_JOYPAD, ISR_JOYPAD)) return 1;
    return 0;
}

static void fetch_instruction(bc_cpu_t *cpu, uint16_t where) {
    uint8_t *insn_loc = bc_mmap_calc(&cpu->mem, where);
    // debug_log("calced ip: %x for pc: %x", insn_loc - cpu->mem.rom->bank1, cpu->regs.PC);
    uint8_t op = *insn_loc;
    const insn_desc_t *t;
    uint16_t param = 0;

    if (op == 0xcb) {
        param = *(insn_loc + 1);
        t = select_extended_instruction(param);
    } else {
        t = &instructions[op];
        switch (t->param_count) {
        case 2:  param = insn_loc[1] | (insn_loc[2] << 8); break;
        case 1:  param = insn_loc[1]; break;
        case 0:  param = 0; break;
        default: panic("only two param bytes are supported - opcode %x has %d", op, t->param_count);
        }
    }

    cpu->current_instruction = t;
    cpu->pc_of_current_instruction = where;
    cpu->instruction_param = param;
}

void bc_cpu_step(bc_cpu_t *cpu, int clocks) {
    debug_assert(clocks % 4 == 0, "clocks need to be a multiple of 4");

    while (clocks) {
        //debug_log("proc loop: starting with %d budget", clocks);
        if (cpu->cycles_for_stall) {
            int leftover = clocks - cpu->cycles_for_stall;
            if (leftover < 0) {
                cpu->cycles_for_stall = -leftover;
                cpu->stalled_cycles += clocks;
                return;
            } else {
                clocks = leftover + ((cpu->stalled_cycles + cpu->cycles_for_stall) & cpu->stall_counts_towards_budget);
                cpu->cycles_for_stall = 0;
                cpu->stalled_cycles = 0;
            }

            continue;
        }

        if (do_interrupts(cpu)) {
            continue;
        }

        if (cpu->halt) {
            // We still need to service timers
            if (clocks >= 16) {
                bc_timer_add_cycles(cpu, 16);
                clocks -= 16;
            } else {
                bc_timer_add_cycles(cpu, clocks);
                clocks = 0;
            }
            continue;
        }

        if (cpu->regs.PC != cpu->pc_of_current_instruction) {
            fetch_instruction(cpu, cpu->regs.PC);
            #if SIMULATE_PIPELINE
            n_fetch_fails++;
            #endif
        }

        if (cpu->current_instruction->ncycles > clocks) {
            cpu->cycles_for_stall = cpu->current_instruction->ncycles - clocks;
            cpu->stalled_cycles = clocks;
            cpu->stall_counts_towards_budget = STALL_TYPE_FRONT;
            break;
        } else {
            const insn_desc_t *t = cpu->current_instruction;
            #if SIMULATE_PIPELINE
            uint16_t save_pc = cpu->regs.PC;
            #endif
            uint16_t save_param = cpu->instruction_param;
            cpu->regs.PC += t->param_count + 1;

            #if SIMULATE_PIPELINE
            // Fetch the next instruction "concurrently" with executor.
            fetch_instruction(cpu, save_pc + t->param_count + 1);
            n_instructions++;
            #endif

            t->executor(cpu, t->opcode, 0, save_param);
            bc_timer_add_cycles(cpu, t->ncycles);
            clocks -= t->ncycles;
        }
    }
}

void bc_cpu_reset(bc_cpu_t *cpu) {
    cpu->regs.A = 0x01;
    cpu->regs.CPSR = 0xB0;
    cpu->regs.B = 0x00;
    cpu->regs.C = 0x13;
    cpu->regs.D = 0x00;
    cpu->regs.E = 0xD8;
    cpu->regs.H = 0x01;
    cpu->regs.L = 0x4D;
    cpu->regs.SP = 0xFFFE;
    cpu->regs.PC = 0x0100;
    bc_mmap_putvalue(&cpu->mem, 0xFF05, 0);
    bc_mmap_putvalue(&cpu->mem, 0xFF06, 0); // timer mod: 0
    bc_mmap_putvalue(&cpu->mem, 0xFF07, 0); // timer ctl: 4.096khz

    bc_mmap_putvalue(&cpu->mem, 0xFF10, 0x80); 
    bc_mmap_putvalue(&cpu->mem, 0xFF11, 0xBF); 
    bc_mmap_putvalue(&cpu->mem, 0xFF12, 0xF3); 
    bc_mmap_putvalue(&cpu->mem, 0xFF14, 0xBF); 
    bc_mmap_putvalue(&cpu->mem, 0xFF16, 0x3F); 
    bc_mmap_putvalue(&cpu->mem, 0xFF17, 0x00); 
    bc_mmap_putvalue(&cpu->mem, 0xFF19, 0xBF); 
    bc_mmap_putvalue(&cpu->mem, 0xFF1A, 0x7F); 
    bc_mmap_putvalue(&cpu->mem, 0xFF1B, 0xFF); 
    bc_mmap_putvalue(&cpu->mem, 0xFF1C, 0x9F); 
    bc_mmap_putvalue(&cpu->mem, 0xFF1E, 0xBF); 
    bc_mmap_putvalue(&cpu->mem, 0xFF20, 0xFF); 
    bc_mmap_putvalue(&cpu->mem, 0xFF21, 0x00); 
    bc_mmap_putvalue(&cpu->mem, 0xFF22, 0x00); 
    bc_mmap_putvalue(&cpu->mem, 0xFF23, 0xBF); 
    bc_mmap_putvalue(&cpu->mem, 0xFF24, 0x77); 
    bc_mmap_putvalue(&cpu->mem, 0xFF25, 0xF3); 
    bc_mmap_putvalue(&cpu->mem, 0xFF26, 0xF1); 

    bc_mmap_putvalue(&cpu->mem, 0xFF40, 0x91);
    bc_mmap_putvalue(&cpu->mem, 0xFF42, 0x00);
    bc_mmap_putvalue(&cpu->mem, 0xFF43, 0x00);
    bc_mmap_putvalue(&cpu->mem, 0xFF45, 0x00);
    bc_mmap_putvalue(&cpu->mem, 0xFF47, 0xFC);
    bc_mmap_putvalue(&cpu->mem, 0xFF48, 0xFF);
    bc_mmap_putvalue(&cpu->mem, 0xFF49, 0xFF);
    bc_mmap_putvalue(&cpu->mem, 0xFF4A, 0x00);
    bc_mmap_putvalue(&cpu->mem, 0xFF4B, 0x00);

    cpu->irq_mask = 0;
}

void bc_cpu_release(bc_cpu_t *cpu) {
    bc_mmap_release(&cpu->mem);
    free(cpu);
}

/* TODO */
// Instruction 0xD3
// "put16 on MBC", bank switching
