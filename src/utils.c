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

void Utils_WorldCoordToScreen(Vec2F *point, float fov) {
    // point->x = WINDOW_W * (point->x + (fov / 2.0f)) / fov;
    // point->y = WINDOW_H * (point->y + (-fov / 2.0f)) / -fov;
    point->x += fov;
    point->y += -fov;
    point->y *= -1;
}