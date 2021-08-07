#include "snake.h"

snake init_snake(uint32_t *buffer, int start_x, int start_y) {
    snake s;
    s.x = start_x;
    s.y = start_y;
    s.size = 1;
    s.side_length = 8;
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
        draw_rect(buffer, current->x, current->y, s->side_length, s->side_length, 0x38761D);
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
    if (SCREEN_WIDTH < s->x + s->side_length ||
        SCREEN_HEIGHT < s->y + s->side_length ||
        0 > s->x + s->side_length ||
        0 > s->y + s->side_length) {
        return 1;
    }

    snake copy = *s;
    snake *n = s->next;

    while (n != NULL) {
        if (copy.x <= n->x + n->side_length &&
            copy.x + copy.side_length > n->x &&
            copy.y <= n->y + n->side_length &&
            copy.y + copy.side_length > n->y) {
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