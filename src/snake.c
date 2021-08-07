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

// Updates position of the snake
void snake_move(snake *head, char dir) {

    snake copy = *head;

    // Updates position of the head
    switch (dir) {
        case 'u':
            head->y -= 8;
            break;
        case 'd':
            head->y += 8;
            break;
        case 'l':
            head->x -= 8;
            break;
        case 'r':
            head->x += 8;
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
        draw_rect(buffer, current->x, current->y, 8, 8, 0x38761D);
        current = current->next;
    }
}

// Creates a new body part of the snake.
void elongate(snake *head) {

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