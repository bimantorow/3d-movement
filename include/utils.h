#ifndef UTILS_H_
#define UTILS_H_

typedef struct Vec2F {
    float x, y;
} Vec2F;

typedef struct Vec3F {
    float x, y, z;
} Vec3F;

typedef struct Vec2 {
    int x, y;
} Vec2;

void Utils_RotateAlongY(Vec3F *point, float theta);
void Utils_RotateAlongX(Vec3F *point, float theta);
Vec2F Utils_WorldCoordToScreen(Vec2F point, float fov);

#endif