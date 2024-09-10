#ifndef PLAYER_H_
#define PLAYER_H_

#include "utils.h"

#define FOCAL 5

typedef struct Player {
    Vec3F pos;
    Vec3F vel;
    Vec2F vel_cam;
    float pitch, yaw, fov;
} Player;

Player *Player_Create(void);
void Player_UpdateDirection(Player *player, SDL_Event event);
void Player_UpdatePos(Player *player, float delta_time);
void Player_Free(Player *player);

#endif