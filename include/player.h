#ifndef PLAYER_H_
#define PLAYER_H_

#include "utils.h"

#define FOCAL 10

typedef struct Player {
    Vec3F pos;
    Vec3F vel;
    float pitch, yaw, fov;
} Player;

Player *Player_Create(void);
void Player_Free(Player *player);

#endif