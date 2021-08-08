#pragma once

#ifndef SNAKE_H_
#define SNAKE_H_

#include <stdlib.h>
#include <stdio.h>
#include "render.h"

typedef struct snake {
    int x, y;
    int size;
    int pixel_size;
    struct snake *next;
} snake;

snake init_snake(uint32_t *buffer, int start_x, int start_y);
void snake_move(snake *s, char dir);
void draw_snake(uint32_t *buffer, snake *s);
void elongate(snake *head, int n);
int dead_collision(snake *s);
void print_snake(snake *s);

#endif