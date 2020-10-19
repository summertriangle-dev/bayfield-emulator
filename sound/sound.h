#ifndef SOUND_H
#define SOUND_H

#include <stdint.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*sound_feed_buffer_t)(int16_t *samples, size_t length, void *context);

typedef struct {
    int ve_direction;
    int ve_init_volume;
    int ve_ctr_base;

    int ve_cur_volume;
    int ve_cur_tick;
    int ve_cur_enabled;
} sound_ve_t;

typedef struct {
    sound_feed_buffer_t feed_callback;
    void *feed_context;

    int16_t *prod_buffer;
    size_t prod_bufsize;
    int prod_count;

    // internal state ---------------------------

    uint32_t prod_tick_base;
    uint32_t prod_tick;

    uint32_t clocks;
    uint32_t master_enable;
    // FF26 contents
    uint8_t status_reg;
    uint8_t step;

    // Bit 7 - Output sound 4 to left terminal
    // Bit 6 - Output sound 3 to left terminal
    // Bit 5 - Output sound 2 to left terminal
    // Bit 4 - Output sound 1 to left terminal
    // Bit 3 - Output sound 4 to right terminal
    // Bit 2 - Output sound 3 to right terminal
    // Bit 1 - Output sound 2 to right terminal
    // Bit 0 - Output sound 1 to right terminal
    uint8_t pan_reg;

    int volume_left;
    int volume_right;

    // channel 1: square wave
    int square1_lenable;
    int square1_lctr;
    int square1_freq;
    int square1_timebase;
    int square1_duty_shape;
    sound_ve_t s1_envelope;

    int square1_tick;
    int square1_duty;

    // channel 2: square wave without freq sweep
    int square2_lenable;
    int square2_lctr;
    int square2_freq;
    int square2_timebase;
    int square2_duty_shape;
    sound_ve_t s2_envelope;

    int square2_tick;
    int square2_duty;

    // channel 3: wave unit
    // ch3 length unit enabled 0/1
    int wave_lenable;
    // ch3 length counter 0-256
    int wave_lctr;
    // ch3 enabled flag
    int wave_play;
    // ch3 sample shift value (0-4)
    int wave_volume;
    // raw frequency value (0-2048)
    int wave_freq;
    // number of clocks between advancing read head (internal)
    int wave_timebase;
    // ch3 advance counter (0-wave_timebase)
    int wave_tick;
    // sample ram 32 * 4bits
    uint8_t wave_pram[16];
    // read head (0-32)
    int wave_pread;

    int noise_lenable;
    int noise_lctr;
    // 15 bit lfsr
    uint32_t noise_reg;
    // reduce lfsr range?
    uint32_t noise_low: 1,
    // number of clocks between advancing lfsr
             noise_timebase: 16;
    sound_ve_t noise_envelope;
    // time until advancing lfsr (0-noise_timebase)
    int noise_tick;
} sound_ctlr_t;

// emucore compatibility

// typedef struct bc_cpu bc_cpu_t;
typedef uint8_t (*snd_mmio_write_t)(void *, void *, uint16_t, uint8_t);
typedef uint8_t (*snd_mmio_read_t)(void *, void *, uint16_t, uint8_t);
typedef void (*snd_mmio_add_observer_t)(void *, uint16_t, snd_mmio_write_t, snd_mmio_read_t, void *);

void sound_init(sound_ctlr_t *state);
void sound_install_regs(sound_ctlr_t *state, void *target, snd_mmio_add_observer_t reg_func);
void sound_set_output(sound_ctlr_t *state, int samples_per_second, sound_feed_buffer_t callback, void *context);
void sound_run_controller(sound_ctlr_t *state, int ncyc);

#ifdef __cplusplus
}
#endif

#endif