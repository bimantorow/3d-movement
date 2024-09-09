#ifndef PLAYER_H_
#define PLAYER_H_

#include "utils.h"

#define FOCAL 40

typedef struct Player {
    Vec3F pos;
    Vec2F vel;
    float pitch, yaw, fov;
} Player;

#endif