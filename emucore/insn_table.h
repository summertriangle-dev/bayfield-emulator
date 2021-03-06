#ifdef INSTRUCTION_TABLE
#include "insn.h"

insn_desc_t const instructions[256] = {
    INSN_ENTRY(0x0, 0,  4, IMP_nop),
    INSN_ENTRY(0x1, 2, 12, IMP_insn_ld_16s),
    INSN_ENTRY(0x2, 0,  8, IMP_insn_store_A),
    INSN_ENTRY(0x3, 0,  8, IMP_insn_incdec16),
    INSN_ENTRY(0x4, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x5, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x6, 1,  8, IMP_insn_ld_immediate),
    INSN_ENTRY(0x7, 0,  4, IMP_rot_left),
    INSN_ENTRY(0x8, 2, 20, IMP_insn_ld_16s),
    INSN_ENTRY(0x9, 0,  8, IMP_insn_add_regs),
    INSN_ENTRY(0xa, 0,  8, IMP_insn_ld_indirect),
    INSN_ENTRY(0xb, 0,  8, IMP_insn_incdec16),
    INSN_ENTRY(0xc, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0xd, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0xe, 1,  8, IMP_insn_ld_immediate),
    INSN_ENTRY(0xf, 0,  4, IMP_rot_right),
    INSN_ENTRY(0x10, 1,  4, IMP_stop),
    INSN_ENTRY(0x11, 2, 12, IMP_insn_ld_16s),
    INSN_ENTRY(0x12, 0,  8, IMP_insn_store_A),
    INSN_ENTRY(0x13, 0,  8, IMP_insn_incdec16),
    INSN_ENTRY(0x14, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x15, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x16, 1,  8, IMP_insn_ld_immediate),
    INSN_ENTRY(0x17, 0,  4, IMP_rot_left),
    INSN_ENTRY(0x18, 1,  8, IMP_jump_rel), // 12 clk, but executor stalls 4
    INSN_ENTRY(0x19, 0,  8, IMP_insn_add_regs),
    INSN_ENTRY(0x1a, 0,  8, IMP_insn_ld_indirect),
    INSN_ENTRY(0x1b, 0,  8, IMP_insn_incdec16),
    INSN_ENTRY(0x1c, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x1d, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x1e, 1,  8, IMP_insn_ld_immediate),
    INSN_ENTRY(0x1f, 0,  4, IMP_rot_right),
    INSN_ENTRY(0x20, 1,  8, IMP_jump_rel),
    INSN_ENTRY(0x21, 2, 12, IMP_insn_ld_16s),
    INSN_ENTRY(0x22, 0,  8, IMP_insn_store_A),
    INSN_ENTRY(0x23, 0,  8, IMP_insn_incdec16),
    INSN_ENTRY(0x24, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x25, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x26, 1,  8, IMP_insn_ld_immediate),
    INSN_ENTRY(0x27, 0,  4, IMP_insn_daa),
    INSN_ENTRY(0x28, 1,  8, IMP_jump_rel),
    INSN_ENTRY(0x29, 0,  8, IMP_insn_add_regs),
    INSN_ENTRY(0x2a, 0,  8, IMP_insn_ld_indirect),
    INSN_ENTRY(0x2b, 0,  8, IMP_insn_incdec16),
    INSN_ENTRY(0x2c, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x2d, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x2e, 1,  8, IMP_insn_ld_immediate),
    INSN_ENTRY(0x2f, 0,  4, IMP_cpl),
    INSN_ENTRY(0x30, 1,  8, IMP_jump_rel),
    INSN_ENTRY(0x31, 2, 12, IMP_insn_ld_16s),
    INSN_ENTRY(0x32, 0,  8, IMP_insn_store_A),
    INSN_ENTRY(0x33, 0,  8, IMP_insn_incdec16),
    INSN_ENTRY(0x34, 0, 12, IMP_insn_incr8),
    INSN_ENTRY(0x35, 0, 12, IMP_insn_incr8),
    INSN_ENTRY(0x36, 1, 12, IMP_insn_ld_immediate),
    INSN_ENTRY(0x37, 0,  4, IMP_scf),
    INSN_ENTRY(0x38, 1,  8, IMP_jump_rel),
    INSN_ENTRY(0x39, 0,  8, IMP_insn_add_regs),
    INSN_ENTRY(0x3a, 0,  8, IMP_insn_ld_indirect),
    INSN_ENTRY(0x3b, 0,  8, IMP_insn_incdec16),
    INSN_ENTRY(0x3c, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x3d, 0,  4, IMP_insn_incr8),
    INSN_ENTRY(0x3e, 1,  8, IMP_insn_ld_immediate),
    INSN_ENTRY(0x3f, 0,  4, IMP_ccf),
    INSN_ENTRY(0x40, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x41, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x42, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x43, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x44, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x45, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x46, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x47, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x48, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x49, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x4a, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x4b, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x4c, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x4d, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x4e, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x4f, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x50, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x51, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x52, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x53, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x54, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x55, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x56, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x57, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x58, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x59, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x5a, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x5b, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x5c, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x5d, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x5e, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x5f, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x60, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x61, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x62, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x63, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x64, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x65, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x66, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x67, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x68, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x69, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x6a, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x6b, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x6c, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x6d, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x6e, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x6f, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x70, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x71, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x72, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x73, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x74, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x75, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x76, 0,  4, IMP_stop),
    INSN_ENTRY(0x77, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x78, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x79, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x7a, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x7b, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x7c, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x7d, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x7e, 0,  8, IMP_insn_ld8),
    INSN_ENTRY(0x7f, 0,  4, IMP_insn_ld8),
    INSN_ENTRY(0x80, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x81, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x82, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x83, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x84, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x85, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x86, 0,  8, IMP_insn_add8),
    INSN_ENTRY(0x87, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x88, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x89, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x8a, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x8b, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x8c, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x8d, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x8e, 0,  8, IMP_insn_add8),
    INSN_ENTRY(0x8f, 0,  4, IMP_insn_add8),
    INSN_ENTRY(0x90, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x91, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x92, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x93, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x94, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x95, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x96, 0,  8, IMP_insn_sub8),
    INSN_ENTRY(0x97, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x98, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x99, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x9a, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x9b, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x9c, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x9d, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0x9e, 0,  8, IMP_insn_sub8),
    INSN_ENTRY(0x9f, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0xa0, 0,  4, IMP_insn_and8),
    INSN_ENTRY(0xa1, 0,  4, IMP_insn_and8),
    INSN_ENTRY(0xa2, 0,  4, IMP_insn_and8),
    INSN_ENTRY(0xa3, 0,  4, IMP_insn_and8),
    INSN_ENTRY(0xa4, 0,  4, IMP_insn_and8),
    INSN_ENTRY(0xa5, 0,  4, IMP_insn_and8),
    INSN_ENTRY(0xa6, 0,  8, IMP_insn_and8),
    INSN_ENTRY(0xa7, 0,  4, IMP_insn_and8),
    INSN_ENTRY(0xa8, 0,  4, IMP_insn_xor8),
    INSN_ENTRY(0xa9, 0,  4, IMP_insn_xor8),
    INSN_ENTRY(0xaa, 0,  4, IMP_insn_xor8),
    INSN_ENTRY(0xab, 0,  4, IMP_insn_xor8),
    INSN_ENTRY(0xac, 0,  4, IMP_insn_xor8),
    INSN_ENTRY(0xad, 0,  4, IMP_insn_xor8),
    INSN_ENTRY(0xae, 0,  8, IMP_insn_xor8),
    INSN_ENTRY(0xaf, 0,  4, IMP_insn_xor8),
    INSN_ENTRY(0xb0, 0,  4, IMP_insn_or8),
    INSN_ENTRY(0xb1, 0,  4, IMP_insn_or8),
    INSN_ENTRY(0xb2, 0,  4, IMP_insn_or8),
    INSN_ENTRY(0xb3, 0,  4, IMP_insn_or8),
    INSN_ENTRY(0xb4, 0,  4, IMP_insn_or8),
    INSN_ENTRY(0xb5, 0,  4, IMP_insn_or8),
    INSN_ENTRY(0xb6, 0,  8, IMP_insn_or8),
    INSN_ENTRY(0xb7, 0,  4, IMP_insn_or8),
    INSN_ENTRY(0xb8, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0xb9, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0xba, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0xbb, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0xbc, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0xbd, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0xbe, 0,  8, IMP_insn_sub8),
    INSN_ENTRY(0xbf, 0,  4, IMP_insn_sub8),
    INSN_ENTRY(0xc0, 0,  8, IMP_call_ret_absolute),
    INSN_ENTRY(0xc1, 0, 12, IMP_pop_pair),
    INSN_ENTRY(0xc2, 2, 12, IMP_jump_absolute),
    INSN_ENTRY(0xc3, 2, 12, IMP_jump_absolute), // 16 clk, but executor stalls 4
    INSN_ENTRY(0xc4, 2, 12, IMP_call_ret_absolute),
    INSN_ENTRY(0xc5, 0, 16, IMP_push_pair),
    INSN_ENTRY(0xc6, 1,  8, IMP_insn_add8),
    INSN_ENTRY(0xc7, 0, 16, IMP_rst_vec),
    INSN_ENTRY(0xc8, 0,  8, IMP_call_ret_absolute),
    INSN_ENTRY(0xc9, 0,  4, IMP_call_ret_absolute), // 16 clk, but executor stalls 12
    INSN_ENTRY(0xca, 2, 12, IMP_jump_absolute),
    INSN_ENTRY(0xcb, 0,  4, NULL),
    INSN_ENTRY(0xcc, 2, 12, IMP_call_ret_absolute),
    INSN_ENTRY(0xcd, 2, 12, IMP_call_ret_absolute), // 24 clk, but executor stalls 12
    INSN_ENTRY(0xce, 1,  8, IMP_insn_add8),
    INSN_ENTRY(0xcf, 0, 16, IMP_rst_vec),
    INSN_ENTRY(0xd0, 0,  8, IMP_call_ret_absolute),
    INSN_ENTRY(0xd1, 0, 12, IMP_pop_pair),
    INSN_ENTRY(0xd2, 2, 12, IMP_jump_absolute),
    INSN_ENTRY(0xd3, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xd4, 2, 12, IMP_call_ret_absolute),
    INSN_ENTRY(0xd5, 0, 16, IMP_push_pair),
    INSN_ENTRY(0xd6, 1,  8, IMP_insn_sub8),
    INSN_ENTRY(0xd7, 0, 16, IMP_rst_vec),
    INSN_ENTRY(0xd8, 0,  8, IMP_call_ret_absolute),
    INSN_ENTRY(0xd9, 0, 16, IMP_reti), 
    INSN_ENTRY(0xda, 2, 12, IMP_jump_absolute),
    INSN_ENTRY(0xdb, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xdc, 2, 12, IMP_call_ret_absolute),
    INSN_ENTRY(0xdd, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xde, 1,  8, IMP_insn_sub8),
    INSN_ENTRY(0xdf, 0, 16, IMP_rst_vec),
    INSN_ENTRY(0xe0, 1, 12, IMP_insn_ld_absolute),
    INSN_ENTRY(0xe1, 0, 12, IMP_pop_pair),
    INSN_ENTRY(0xe2, 0,  8, IMP_insn_ld_absolute),
    INSN_ENTRY(0xe3, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xe4, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xe5, 0, 16, IMP_push_pair),
    INSN_ENTRY(0xe6, 1,  8, IMP_insn_and8),
    INSN_ENTRY(0xe7, 0, 16, IMP_rst_vec),
    INSN_ENTRY(0xe8, 1, 16, IMP_insn_add_sp_imm8),
    INSN_ENTRY(0xe9, 0,  4, IMP_jump_absolute),
    INSN_ENTRY(0xea, 2, 16, IMP_insn_ld_absolute),
    INSN_ENTRY(0xeb, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xec, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xed, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xee, 1,  8, IMP_insn_xor8),
    INSN_ENTRY(0xef, 0, 16, IMP_rst_vec),
    INSN_ENTRY(0xf0, 1, 12, IMP_insn_ld_absolute),
    INSN_ENTRY(0xf1, 0, 12, IMP_pop_pair),
    INSN_ENTRY(0xf2, 0,  8, IMP_insn_ld_absolute),
    INSN_ENTRY(0xf3, 0,  4, IMP_edi),
    INSN_ENTRY(0xf4, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xf5, 0, 16, IMP_push_pair),
    INSN_ENTRY(0xf6, 1,  8, IMP_insn_or8),
    INSN_ENTRY(0xf7, 0, 16, IMP_rst_vec),
    INSN_ENTRY(0xf8, 1, 12, IMP_insn_add_sp_imm8),
    INSN_ENTRY(0xf9, 0,  8, IMP_insn_ld_16s),
    INSN_ENTRY(0xfa, 2, 16, IMP_insn_ld_absolute),
    INSN_ENTRY(0xfb, 0,  4, IMP_edi),
    INSN_ENTRY(0xfc, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xfd, 0,  0, IMP_undefined_instruction),
    INSN_ENTRY(0xfe, 1,  8, IMP_insn_sub8),
    INSN_ENTRY(0xff, 0, 16, IMP_rst_vec),
};

#endif
