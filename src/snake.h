#pragma once
#include "physics.h"
#include "render.h"

struct snake
{
    struct vector2 pos;
    int size;
    char dir;
};

void init_snake(uint32_t *pixel_buffer, int size);
void move(struct vector2 *pos, char dir);

// void inc_size(uint32_t *pixel_buffer, snake *s, int *size);
// int checkCollision(snake *s);
// void turn(snake *s, vector2 *turnPoint);