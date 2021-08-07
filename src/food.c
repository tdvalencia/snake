#include <stdio.h>

#include "render.h"
#include "food.h"

uint32_t f_colors[4] = {
    0x1B4FD9,
    0xC83B3B,
    0xED7714,
    0xF9E130
};

food init_food(snake *s) {
    food f;
    f.x = rand() % (SCREEN_WIDTH - 50) + 25;
    f.y = rand() % (SCREEN_HEIGHT - 50) + 25;
    f.color = f_colors[rand() % 4];

    while (s != NULL) {
        if (s->x == f.x && s->y == f.y) {
            f.x = rand() % SCREEN_WIDTH;
            f.y = rand() % SCREEN_HEIGHT;
        }
        s = s->next;
    }

    return f;
}

void draw_food(uint32_t *buffer, food *f) {
    draw_rect(buffer, f->x, f->y, 5, 5, f->color);
}

int check_collision(snake *s, food *f) {
    if (s->x == f->x || s->y == f->y) {
        return 1;
    }
    return 0;
}

void print_food(food *f) {
    printf("----food----\n");
    printf("pos:\t(%d, %d)\n", f->x, f->y);
    printf("color:\t%d\n", f->color);
    printf("------------\n");
}