#include <SDL2/SDL.h>
#include <string.h>
#include "gameobj.h"
#include "utils.h"
#include "player.h"

GameObj *GameObj_CreateCube(Vec3F *verts) {
    int n_vert = 8;
    int n_edge = 12;
    GameObj *cube = malloc(sizeof(GameObj));
    cube->verts = calloc(n_vert, sizeof(Vec3F));
    cube->camera_verts = calloc(n_vert, sizeof(Vec3F));
    cube->proj_verts = calloc(n_vert, sizeof(Vec2F));
    cube->n_vert = n_vert;
    cube->edges = calloc(n_edge, sizeof(Vec2));
    cube->n_edge = n_edge;

    for (int i = 0; i < n_vert; i++) {
        cube->verts[i] = verts[i];
    }

    bzero(cube->camera_verts, n_vert * sizeof(Vec3F));
    bzero(cube->proj_verts, n_vert * sizeof(Vec2F));

    cube->edges[0] = (Vec2){ 0, 1 };
    cube->edges[1] = (Vec2){ 1, 2 };
    cube->edges[2] = (Vec2){ 2, 3 };
    cube->edges[3] = (Vec2){ 3, 0 };
    cube->edges[4] = (Vec2){ 4, 5 };
    cube->edges[5] = (Vec2){ 5, 6 };
    cube->edges[6] = (Vec2){ 6, 7 };
    cube->edges[7] = (Vec2){ 7, 4 };
    cube->edges[8] = (Vec2){ 0, 4 };
    cube->edges[9] = (Vec2){ 1, 5 };
    cube->edges[10] = (Vec2){ 2, 6 };
    cube->edges[11] = (Vec2){ 3, 7 };

    return cube;
}

void GameObj_Free(GameObj *obj) {
    free(obj->edges);
    free(obj->proj_verts);
    free(obj->camera_verts);
    free(obj->verts);
    free(obj);
}
void GameObj_Render(SDL_Renderer *renderer, SDL_Texture *texture, Player *player, GameObj *obj) {
    /* TODO: Translate game object so that the player is at the origin.
    Rotate it according to the player's pitch and yaw. Project it onto a 2d plane. Check
    if the projected point is inside the player's fov. If yes, then draw it. If not, leave it be.
    */

    // Calculate points to draw
    for (int i = 0; i < obj->n_vert; i++) {
        Vec3F transformed;
        Vec2F projected;

        // Translation
        transformed.x = obj->verts[i].x - player->pos.x;
        transformed.y = obj->verts[i].y - player->pos.y;
        transformed.z = obj->verts[i].z - player->pos.z;

        // Rotation
        Utils_RotateAlongY(&transformed, -player->yaw);
        Utils_RotateAlongX(&transformed, -player->pitch);

        // Projection
        obj->proj_verts[i].x = (FOCAL / (FOCAL + transformed.z)) * transformed.x;
        obj->proj_verts[i].y = (FOCAL / (FOCAL + transformed.z)) * transformed.y;
    }

    // Draw onto screen
    SDL_SetRenderTarget(renderer, texture);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (int i = 0; i < obj->n_edge; i++) {
        Vec2F origin = obj->proj_verts[obj->edges[i].x];
        Vec2F dest = obj->proj_verts[obj->edges[i].y];
        SDL_RenderDrawLineF(renderer, origin.x, origin.y, dest.x, dest.y);
    }
}

// Rotate along y axis
void GameObj_RotateYaw(GameObj *obj, float theta) {
    for (int i = 0; i < obj->n_vert; i++) {
        Utils_RotateAlongY(&(obj->verts[i]), theta);
    }
}

// Rotate along x axis
void GameObj_RotatePitch(GameObj *obj, float theta) {
    for (int i = 0; i < obj->n_vert; i++) {
        Utils_RotateAlongX(&(obj->verts[i]), theta);
    }
}