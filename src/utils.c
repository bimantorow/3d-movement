#include <math.h>
#include "utils.h"
#include "window.h"

void Utils_RotateAlongY(Vec3F *point, float theta) {
    point->x = cosf(theta) * point->x + sinf(theta) * point->z;
    point->z = -sinf(theta) * point->x + cosf(theta) * point->z;
}

void Utils_RotateAlongX(Vec3F *point, float theta) {
    point->y = cosf(theta) * point->y + -sinf(theta) * point->z;
    point->z = sinf(theta) * point->y + cosf(theta) * point->z;
}

Vec2F Utils_WorldCoordToScreen(Vec2F point) {
    Vec2F res;
    res.x = WINDOW_W * (point.x + (CAMERA_W / 2.0f)) / CAMERA_W;
    res.y = WINDOW_H * (point.y + (CAMERA_H / 2.0f)) / CAMERA_H;
    return res;
}