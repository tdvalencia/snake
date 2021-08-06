#include <SDL2/SDL.h>
#include <stdio.h>

#include "render.h"
#include "snake.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *screen = NULL;

uint32_t *pixels = NULL;

int init();
void close();

int main(int argc, char *args[]) {

    if (init() == 1) {
        return 0;
    }

    int quit = 0;
    snake s = init_snake(pixels, 320, 380);
    char dir = '\0';

    while (quit == 0) {
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            dir = 'u';
                            break;
                        case SDLK_DOWN:
                            dir = 'd';
                            break;
                        case SDLK_LEFT:
                            dir = 'l';
                            break;
                        case SDLK_RIGHT:
                            dir = 'r';
                            break;
                    }
            }
        }

        snake_move(&s, dir);
        draw_snake(pixels, &s);

        SDL_UpdateTexture(screen, NULL, pixels, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, screen, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_Delay(95);
    }

    close();

    return 0;
}

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not be initialized. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    pixels = (Uint32*) malloc((SCREEN_WIDTH * SCREEN_HEIGHT) * sizeof(Uint32));

    if (window == NULL || renderer == NULL) {
        printf("window or renderer could not be initialized. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    return 0;
}

void close() {
    SDL_DestroyWindow(window);
    window = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_Quit();
}