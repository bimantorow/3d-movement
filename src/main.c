#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>
#include "window.h"
#include "player.h"
#include "gameobj.h"

int quit = 0;
int last_frame_time = 0;

void process_input(Player *player) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        Player_UpdateDirection(player, event);
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

void update(GameObj *cube, Player *player) {
    int wait_time = FRAME_TARGET_TIME - (SDL_GetTicks() - last_frame_time);
    if (wait_time > 0) {
        SDL_Delay(wait_time);
    }

    float delta_time = (SDL_GetTicks() - last_frame_time) / 1000.0f;
    last_frame_time = SDL_GetTicks();

    Player_UpdatePos(player, delta_time);
    // float theta = M_PI / 2 * delta_time;
    // GameObj_RotateYaw(cube, theta);
}

void render(SDL_Renderer *renderer, SDL_Texture *texture) {
    SDL_SetRenderTarget(renderer, NULL);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

int main(void) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    Window_Init(&window, &renderer);

    Player *player = Player_Create(500.0f);

    Vec3F start = { -100.0f, 0.0f, 10.0f };
    GameObj *cube = GameObj_Cube(start, 200.0f);

    SDL_Texture *texture = Window_CreateTexture(renderer, player->fov);

    last_frame_time = SDL_GetTicks();

    // Game loop
    while (!quit) {
        process_input(player);
        update(cube, player);
        GameObj_Render(renderer, texture, player, cube);
        render(renderer, texture);
    }

    Window_Destroy(window, renderer);
    Player_Free(player);
    GameObj_Free(cube);
    SDL_DestroyTexture(texture);

    return EXIT_SUCCESS;
}