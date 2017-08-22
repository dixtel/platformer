#ifndef DISTANCE_H
#define DISTANCE_H

#include "include/vectro2.h"

#include <math.h>

static float GetDistance(Vector2f A, Vector2f B) {

    float hypotenuse_square = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
    return sqrt(hypotenuse_square);
}

#endif // DISTANCE_H
