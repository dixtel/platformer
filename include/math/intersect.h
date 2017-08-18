#ifndef INTERSECT_H
#define INTERSECT_H

#include "include/vectro2.h"

Vector2f GetIntersect(Vector2f A1, Vector2f A2, Vector2f B1, Vector2f B2) {

    Vector2f s1, s2;
    s1.x = A2.x - A1.x;
    s1.y = A2.y - A1.y;
    s2.x = B2.x - B1.x;
    s2.y = B2.y - B1.y;

    float s, t;
    s = (-s1.y * (A1.x - B1.x) + s1.x * (A1.y - B1.y)) / (-s2.x * s1.y + s1.x * s2.y);
    t = ( s2.x * (A1.y - B1.y) - s2.y * (A1.x - B1.x)) / (-s2.x * s1.y + s1.x * s2.y);

    if(s >= 0 && s <= 1 && t >= 0 && t <= 1) {

        float x = A1.x + (t * s1.x);
        float y = A1.y + (t * s1.y);

        return Vector2f {x, y};
    }

    return Vector2f {0, 0};
}


#endif // INTERSECT_H
