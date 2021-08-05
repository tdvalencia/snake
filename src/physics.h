#pragma once
#include <stdint.h>
#include <math.h>

struct vector2 {
    float x, y;
};

void add_vector2(struct vector2 *a, struct vector2 *b);

struct vector2 add_vector2_new(struct vector2 *a, struct vector2 *b);

void multiply_vector(struct vector2 *v, float n);

void divide_vector(struct vector2 *v, float n);

void print_vector(struct vector2 *v);