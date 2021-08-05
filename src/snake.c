#include "snake.h"

void init_snake(uint32_t *pixel_buffer, int size) {

    int last =  320 + size;
    int y = 240;

    for (int x = 320; x < last; x++) {
        draw_pixel(pixel_buffer, 320, y, 0xffffffff);
        y++;
    }
}

void move(struct vector2 *pos, char dir) {
    if (dir == 'u') {
        // moveUp
    }
    if (dir == 'd') {
        // moveDown
    }
    if (dir == 'l') {
        // moveLeft
    }
    if (dir == 'r') {
        // moveRight
    }
}