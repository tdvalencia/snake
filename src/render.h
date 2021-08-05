#pragma once
#include <stdint.h>
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/* render.c and render.h:
    The graphics library for the game.
*/

int draw_line(uint32_t *pixel_buffer, int x1, int y1, int x2, int y2, uint32_t color);

int draw_pixel(uint32_t *pixel_buffer, int x, int y, uint32_t color);

void clear_pixels(uint32_t *pixel_buffer, uint32_t color);
