/* 
GPU.CPP
NICK
2019
*/

#include "GPU.h"

#include <iostream> //remove this when debugging is done
#include <string.h>

/* PRIVATE */


/* PUBLIC */

// constructor
GPU::GPU() {
	VRAM = (uint8_t *) malloc(sizeof(uint8_t) * 8 * KB);
	BG_MAP = (uint8_t *) malloc(sizeof(uint8_t) * 32 * 32);
	memset(BG_MAP, 0xFF, (sizeof(uint8_t) * 32 * 32));
	// BG_BUFFER = (uint32_t *) malloc(sizeof(uint32_t) * 256 * 256); // IF YOU RE-ENABLE THIS... (SEE DESTRUCTOR)
	TILES_BG = VRAM;
	TILES_SPRITES = VRAM + (4 * KB); //TODO: offset should be adjustable based on register setting
}

// destructor
GPU::~GPU() {
	free(VRAM);
	free(BG_MAP);
	// free(BG_BUFFER); //... RE-ENABLE THIS TOO
}

// initialize the GPU with a pointer to Window->Surface->Pixels
void GPU::init(uint32_t* ptr_to_win_memory) {
	WINDOW_MEMORY = ptr_to_win_memory;
}

/* FOR DEBUGGING SO THAT SURFACES CAN BE DUMPED EASILY */
void GPU::setBgBufferAddress(uint32_t* buf_addr) {
	BG_BUFFER = buf_addr;
	memset(BG_BUFFER, 0xFFFFFFFF, (sizeof(uint32_t) * 256 * 256));
}

void GPU::setSpriteBufferAddress(uint32_t* buf_addr) {
	SPRITE_BUFFER = buf_addr;
	memset(SPRITE_BUFFER, 0x00FFFFFF, (sizeof(uint32_t) * 256 * 256));
}

void GPU::setWindowBufferAddress(uint32_t* buf_addr) {
	WINDOW_BUFFER = buf_addr;
	memset(WINDOW_BUFFER, 0x00FFFFFF, (sizeof(uint32_t) * 256 * 256));
}

// add a tile to the background area of VRAM
void GPU::add_bg_tile(int id, uint8_t* tile) {
	uint8_t* dest = TILES_BG + id * TILE_SIZE;
	memcpy((void *) dest, (void *) tile, TILE_SIZE);
}

//add a tile to the sprite area of VRAM
void GPU::add_sprite_tile(int id, uint8_t* sprite) {
	uint8_t* dest = TILES_SPRITES + id * TILE_SIZE;
	memcpy((void *) dest, (void *) sprite, TILE_SIZE);
}

//set an area in backgroud to render as tile [id] from backgroud/shared VRAM
void GPU::set_bg_tile(int x, int y, int id) {
	BG_MAP[x + y * 32] = id;
}


//set scroll register values
void GPU::set_scroll(int8_t x, int8_t y) {
	GPU_REG_SCROLLY = y;
	GPU_REG_SCROLLX = x;
}

//draw the sprites to a buffer
void GPU::draw_sprites() {
	return;
}

//draw the window object to a buffer
void GPU::draw_window() {
	return;
}

//render tiles from background map, referring to background/shared VRAM for textures
void GPU::draw_bg() {
	// loop over the tile map and look for tiles to be drawn
	for (int tile_map_y = 0; tile_map_y < 32; tile_map_y++) {
		for (int tile_map_x = 0; tile_map_x < 32; tile_map_x++) {

			// this value in the map indicated it would be this tile (if it exists)
			uint8_t tile_id = BG_MAP[tile_map_x + tile_map_y * 32];

			// not a tile (memset in constructor guarantees this)
			if (tile_id == 0xFF) continue;

			uint16_t* TILE_ADDR = (uint16_t *) TILES_BG + tile_id * 8;

			// copy [tile -> buffer] loops
			for (int y = 0; y < 8; y++)	{
				for (int x = 0; x < 8; x++) {

					// get value of line of pixels
					uint16_t A = TILE_ADDR[y];

					// shuffle bits about to make sense of GB's storage format
					// 0b0123456789abcdef -> 80, 91, a2, b3, etc.
					uint8_t B = ((A >> (15 - x) & 0x01) + (((A >> (7 - x)) & 0x01) << 1));

					// absolute x and y coordinates to simplify math
					int abs_x = (x + tile_map_x * 8);
					int abs_y = (y + tile_map_y * 8);
					int buf_pos = abs_x + abs_y * 256;

					// look up what colour the saved bits represent, copy it over to buffer
					BG_BUFFER[buf_pos] = PALETTE_BG[B];
				}
			}
		}
	}
}

//assemble all buffers and produce final frame
void GPU::render() {
	for (int y = 0; y < 144; y++) {
		for (int x = 0; x < 160; x++) {
			// copy background buffer over
			WINDOW_MEMORY[x + GPU_REG_SCROLLX + 160 * (y + GPU_REG_SCROLLY)] = BG_BUFFER[x + 256 * y];
		}
		// H-BLANK
	}
	// V-BLANK
}

