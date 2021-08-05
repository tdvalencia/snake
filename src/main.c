#include <SDL2/SDL.h>
#include <stdlib.h>
#include <stdio.h>

#include "render.h"
#include "snake.h"

int init();
void close();

SDL_Window *window = NULL;
SDL_Renderer *renderer;
SDL_Texture *screen;
uint32_t *pixels = NULL;

int main(int argc, char *args[]) {

    if (init() == 1) {
        return 0;
    }

    int quit = 0;

    while (quit == 0) {
        SDL_PumpEvents();

        const Uint8 *state = SDL_GetKeyboardState(NULL);

        if (state[SDL_SCANCODE_ESCAPE]) {
            quit = 1;
        }

        init_snake(pixels, 2);

        SDL_UpdateTexture(screen, NULL, pixels, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, screen, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    close();
    
    return 0;
}

int init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Video could not be initialized. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("SNAKE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    screen = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    pixels = (Uint32*) malloc((SCREEN_WIDTH * SCREEN_HEIGHT) * sizeof(Uint32));

    if (window == NULL) {
        printf("Cannot create window. %s\n", SDL_GetError());
        return 1;
    }

    if (screen == NULL) {
        printf("Cannot create screen texture. %s\n", SDL_GetError());
        return 1;
    }

    if (pixels == NULL) {
        printf("Cannot create pixel buffer.");
        return 1;
    }

    return 0;
}

void close() {
    free(pixels);

    SDL_DestroyTexture(screen);
    screen = NULL;

    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}