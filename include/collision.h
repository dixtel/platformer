#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL_log.h>

#include "include/rectanglecollision.h"
#include "include/math/intersect.h"
#include "include/math/angle.h"
#include "include/math/distance.h"
#include "include/math/vector.h"
#include "include/math/vector2.h"

#include <vector>
#include <cmath>

const Vector AXIS_X = {1, 0};
const Vector AXIS_Y = {0, 1};

class Collision
{
public:

    Collision();

    bool IsCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> &coliders);
    void SetCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> &coliders);
private:

    std::vector<Vector> ConvertToVectors(RectangleCollision *object, Vector2f center);
    float GetProjection(Vector2f point1, Vector2f point2, Vector axis);
    float GetMinnimumProjection(std::vector<Vector> vectors, Vector axis);
    float GetMaxsimiumProjection(std::vector<Vector> vectors, Vector axis);
};
\
#endif // COLLISION_H
