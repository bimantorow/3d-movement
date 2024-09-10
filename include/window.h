#ifndef WINDOW_H_
#define WINDOW_H_

#include <SDL2/SDL.h>

#define WINDOW_W 800
#define WINDOW_H 800
#define TEXTURE_W 800
#define TEXTURE_H 800
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

void Window_Init(SDL_Window **window, SDL_Renderer **renderer);
void Window_Destroy(SDL_Window *window, SDL_Renderer *renderer);
SDL_Texture *Window_CreateTexture(SDL_Renderer *renderer);

#endif