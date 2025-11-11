#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "window.h"

void err_and_exit(char *func) {
    fprintf(stderr, "%s error: %s\n", func, SDL_GetError());
    exit(EXIT_FAILURE);
}

void Window_Init(SDL_Window **window, SDL_Renderer **renderer) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        err_and_exit("SDL_Init");
    }

    *window = SDL_CreateWindow(
        "3D Movement",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_W,
        WINDOW_H,
        0
    );
    if (!(*window)) {
        err_and_exit("SDL_CreateWindow");
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
    if (!(*renderer)) {
        err_and_exit("SDL_CreateRenderer");
    }
}

void Window_Destroy(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Texture *Window_CreateTexture(SDL_Renderer *renderer, int fov) {
    return SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET, 2 * fov, 2 * fov);
}