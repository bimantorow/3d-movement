#include <SDL2/SDL.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"
#include "utils.h"

#define VEL 10
#define VEL_CAM 1

Player *Player_Create(float fov) {
    Player *player = malloc(sizeof(Player));
    bzero(player, sizeof(Player)); 
    player->fov = fov;
    return player;
}

void Player_UpdateDirection(Player *player, SDL_Event event) {
    switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_w: player->vel.z = VEL; break;
                case SDLK_a: player->vel.x = -VEL; break;
                case SDLK_s: player->vel.z = -VEL; break;
                case SDLK_d: player->vel.x = VEL; break;
                case SDLK_SPACE: player->vel.y = VEL; break;
                case SDLK_LCTRL: player->vel.y = -VEL; break;
                case SDLK_i: player->vel_cam.y = VEL_CAM; break;
                case SDLK_j: player->vel_cam.x = -VEL_CAM; break;
                case SDLK_k: player->vel_cam.y = -VEL_CAM; break;
                case SDLK_l: player->vel_cam.x = VEL_CAM; break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_a:
                case SDLK_d:
                    player->vel.x = 0; break;
                case SDLK_w:
                case SDLK_s:
                    player->vel.z = 0; break;
                case SDLK_SPACE:
                case SDLK_LCTRL:
                    player->vel.y = 0; break;
                case SDLK_i:
                case SDLK_k:
                    player->vel_cam.y = 0; break;
                case SDLK_j:
                case SDLK_l:
                    player->vel_cam.x = 0; break;
            }
            break;
    }
}

void Player_UpdatePos(Player *player, float delta_time) {
    player->pos.x += player->vel.x * delta_time;
    player->pos.y += player->vel.y * delta_time;
    player->pos.z += player->vel.z * delta_time;
    player->yaw += player->vel_cam.x * delta_time;
    player->pitch += player->vel_cam.y * delta_time;
}

void Player_Free(Player *player) {
    free(player);
}