#include <stdio.h>

#include "snake.h"
#include "render.h"

snake init_snake(uint32_t *buffer, int start_x, int start_y) {
    snake s;
    s.x = start_x;
    s.y = start_y;
    s.size = 1;
    s.next = NULL;

    draw_snake(buffer, &s);

    return s;
}

void snake_move(snake *s, char dir) {

    snake *current = s;
    snake *next = current->next;

    switch (dir)
    {
        case 'u':
            s->y -= 8;
            break;
        case 'd':
            s->y += 8;
            break;
        case 'l':
            s->x -= 8;
            break;
        case 'r':
            s->x += 8;
            break;
        default:
            break;
    }

    while (next != NULL) {
        next->x = current->x;
        next->y = current->y;

        current = current->next;
        next = current->next;
    }
}

void draw_snake(uint32_t *buffer, snake *s) {
    clear_buffer(buffer);
    if (s->size != 1) {
        snake *current = s;
        while (current->next != NULL) {
            draw_rect(buffer, current->x, current->y, 10, 10);
            current = current->next;
        }
    }
    else {
        draw_rect(buffer, s->x, s->y, 10, 10);
    }
}

void elongate(snake *head) {

    int x = head->x;
    int y = head->y + 30;
    head->size++;

    snake *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    
    tail->next = (snake *) malloc(sizeof(snake));
    tail->next->x = x;
    tail->next->y = y;
    tail->next->next = NULL;

    printf("elongated. size: %d\n", head->size);
    print_snake(tail);
}

void print_snake(snake *s) {
    printf("snake(%d, %d)\n", s->x, s->y);
}