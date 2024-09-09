#ifndef GAMEOBJ_H_
#define GAMEOBJ_H_

#include "utils.h"

typedef struct GameObj {
    Vec3F *verts;
    Vec3F *camera_verts;
    Vec2F *proj_verts;
    int n_vert;
    Vec2 *edges;
    int n_edge;
} GameObj;

#endif