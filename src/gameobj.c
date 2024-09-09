#include "utils.h"

typedef struct GameObj {
    Vec3 *verts;
    Vec2 *proj_verts;
    int n_vert;
    int *edges;
    int n_edge;
} GameObj;