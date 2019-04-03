#ifndef BAYFIELD_H
#define BAYFIELD_H

#include <SDL2/SDL.h>
#include "emucore.h"
#include "GPU.h"

typedef struct {
    char rom_title[16];
    bc_cpu_t *cpu;
    GPU *gpu;
    SDL_Surface *draw_buffers[2];
    // index of buffer in use
    int drawing_buffer;
    int stop;
} emu_shared_context_t;

void emu_thread_go(emu_shared_context_t *ctx);
void init_cores(emu_shared_context_t *ctx);

bool load_rom(emu_shared_context_t *ctx, const char *filename);

#endif