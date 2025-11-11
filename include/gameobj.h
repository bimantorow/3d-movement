#ifndef GAMEOBJ_H_
#define GAMEOBJ_H_

#include "utils.h"
#include "player.h"

typedef struct GameObj {
    Vec3F *verts;
    Vec3F *camera_verts;
    Vec2F *proj_verts;
    int n_vert;
    Vec2 *edges;
    int n_edge;
} GameObj;

GameObj *GameObj_Cube(Vec3F start, float length);
void GameObj_Free(GameObj *obj);
void GameObj_Render(SDL_Renderer *renderer, SDL_Texture *texture, Player *player, GameObj *obj);
void GameObj_RotateYaw(GameObj *obj, float theta);
void GameObj_RotatePitch(GameObj *obj, float theta);

#endif