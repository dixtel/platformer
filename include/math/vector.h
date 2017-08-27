#ifndef VECTOR_H
#define VECTOR_H

#include "include/math/vector2.h"

struct Vector {

    float x;
    float y;

    float GetDotProduct(Vector axis) {
        return x * axis.x + y * axis.y;
    }
};

#endif // VECTOR_H
