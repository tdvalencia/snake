#include <stdio.h>

#include "snake.h"
#include "render.h"

snake init_snake(uint32_t *buffer, int start_x, int start_y) {
    snake s;
    s.x = start_x;
    s.y = start_y;
    s.next = NULL;

    draw_snake(buffer, &s);

    return s;
}

void snake_move(snake *s, char dir) {
    switch (dir)
    {
        case 'u':
            s->y -= 10;
            break;
        case 'd':
            s->y += 10;
            break;
        case 'l':
            s->x -= 10;
            break;
        case 'r':
            s->x += 10;
            break;
        default:
            break;
    }
}

void draw_snake(uint32_t *buffer, snake *s) {
    clear_buffer(buffer);
    draw_rect(buffer, s->x, s->y, 10, 10);
}

void print_snake(snake *s) {
    printf("snake(%d, %d)\n", s->x, s->y);
}