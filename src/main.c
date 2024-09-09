#include <SDL2/SDL.h>
#include <stdlib.h>
#include "window.h"
#include "player.h"
#include "gameobj.h"

int quit = 0;

void process_input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                quit = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = 1;
                        break;
                }
                break;
        }
    }
}

void render(SDL_Renderer *renderer, SDL_Texture *texture) {
    SDL_SetRenderTarget(renderer, NULL);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

int main(void) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    Window_Init(&window, &renderer);

    Player *player = Player_Create();

    Vec3F verts[] = {
        { -1.0f, -1.0f, 1.0f },
        { 1.0f, -1.0f, 1.0f },
        { 1.0f, -1.0f, 3.0f },
        { -1.0f, -1.0f, 3.0f },
        { -1.0f, 1.0f, 1.0f },
        { 1.0f, 1.0f, 1.0f },
        { 1.0f, 1.0f, 3.0f },
        { -1.0f, 1.0f, 3.0f },
    };
    GameObj *cube = GameObj_Cube(verts);

    SDL_Texture *texture = Window_CreateTexture(renderer);

    // Game loop
    while (!quit) {
        process_input();
        GameObj_Render(renderer, texture, player, cube);
        render(renderer, texture);
    }

    Window_Destroy(window, renderer);
    Player_Free(player);
    GameObj_Free(cube);
    SDL_DestroyTexture(texture);

    return EXIT_SUCCESS;
}