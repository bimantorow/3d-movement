#include <math.h>
#include "utils.h"

void Utils_RotateAlongY(Vec3F *point, float theta) {
    point->x = cosf(theta) * point->x + sinf(theta) * point->z;
    point->z = -sinf(theta) * point->x + cosf(theta) * point->z;
}

void Utils_RotateAlongX(Vec3F *point, float theta) {
    point->y = cosf(theta) * point->y + -sinf(theta) * point->z;
    point->z = sinf(theta) * point->y + cosf(theta) * point->z;
}