#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL.h>

#include "include/rectanglecollision.h"
#include "include/math/intersect.h"

#include <vector>

class Collision
{
public:

    Collision();

    bool IsCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> coliders);

    void SetCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> coliders);
};

#endif // COLLISION_H
