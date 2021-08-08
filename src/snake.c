#include "snake.h"

#define SPEED 8

snake init_snake(uint32_t *buffer, int start_x, int start_y) {
    snake s;
    s.x = start_x;
    s.y = start_y;
    s.size = 1;
    s.pixel_size = 7;
    s.next = NULL;

    elongate(&s, 2);
    draw_snake(buffer, &s);

    return s;
}

// Updates position of the snake
void snake_move(snake *head, char dir) {

    snake copy = *head;

    // Updates position of the head
    switch (dir) {
        case 'u':
            head->y -= SPEED;
            break;
        case 'd':
            head->y += SPEED;
            break;
        case 'l':
            head->x -= SPEED;
            break;
        case 'r':
            head->x += SPEED;
            break;
        default:
            break;
    }

    // Updates positions of the snake body
    while (head->next != NULL) {
        // Set next body to the pos of ahead body
        snake temp = *head->next;
        head->next->x = copy.x;
        head->next->y = copy.y;

        // Reassign
        copy = temp;
        head = head->next;
    }
}

// Clears the screen and redraws all of the snake
void draw_snake(uint32_t *buffer, snake *s) {
    snake *current = s;
    while (current != NULL) {
        draw_rect(buffer, current->x, current->y, s->pixel_size, s->pixel_size, 0x38761D);
        current = current->next;
    }
}

// Creates a new body part of the snake.
void elongate(snake *head, int n) {
    for (int i = 0; i < n; i++) {
        snake *tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        
        tail->next = (snake *) malloc(sizeof(snake));
        tail->next->x = -5;
        tail->next->y = -5;
        tail->next->next = NULL;
        head->size++;
    }
    printf("score: %d\n", head->size);
}

int dead_collision(snake *s) {
    if (SCREEN_WIDTH < s->x + s->pixel_size ||
        SCREEN_HEIGHT < s->y + s->pixel_size ||
        0 > s->x + s->pixel_size ||
        0 > s->y + s->pixel_size) {
        return 1;
    }

    snake copy = *s;
    snake *n = s->next;

    while (n != NULL) {
        if (copy.x <= n->x + n->pixel_size &&
            copy.x + copy.pixel_size >= n->x &&
            copy.y <= n->y + n->pixel_size &&
            copy.y + copy.pixel_size >= n->y) {
            return 1;
        }
        n = n->next;
    }
    return 0;
}

// Iterates through entire snake and prints it out
void print_snake(snake *s) {
    snake *cur = s;
    int i = 0;
    printf("----snake----\n");
    while (cur != NULL) {
        printf("%d: %d %d\n", i, cur->x, cur->y);
        i++;
        cur = cur->next;
    }
    printf("-------------\n");
}