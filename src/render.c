#include <SDL2/SDL.h>
#include "render.h"

int draw_pixel(uint32_t *pixel_buffer, int x, int y, uint32_t color) {

    if (x < 0 || y < 0) {
        return 1;
    }

    if (x > SCREEN_WIDTH || y > SCREEN_HEIGHT) {
        return 1;
    }

    int position = y * SCREEN_WIDTH + x;
    pixel_buffer[position] = color;

    return 0;
}

int draw_rect(uint32_t *pixel_buffer, int x, int y, int w, int h) {
    for (int r = y; r < (y+h); r++) {
        for (int c = x; c < (x+w); c++) {
            draw_pixel(pixel_buffer, c, r, 0xffffffff);
        }
    }

    return 0;
}

void clear_buffer(uint32_t *pixel_buffer) {
    for (int r = 0; r < SCREEN_HEIGHT; r++) {
        for (int c = 0; c < SCREEN_WIDTH; c++) {
            draw_pixel(pixel_buffer, c, r, 0x00000000);
        }
    }
}