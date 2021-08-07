#pragma once

#ifndef FOOD_H_
#define FOOD_H_

#include "render.h"
#include "snake.h"

typedef struct food {
    int x, y;
    uint32_t color;
} food;

food init_food(snake *s);
void draw_food(uint32_t *buffer, food *f);
int check_collision(snake *s, food *f);
void print_food(food *f);

#endif