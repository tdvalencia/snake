#pragma once

#ifndef SNAKE_H_
#define SNAKE_H_

#include "render.h"

typedef struct snake {
    int x, y;
    int size;
    struct snake *next;
} snake;

snake init_snake(uint32_t *buffer, int start_x, int start_y);
void snake_move(snake *s, char dir);
void draw_snake(uint32_t *buffer, snake *s);
void elongate(snake *head);
void print_snake(snake *s);

#endif