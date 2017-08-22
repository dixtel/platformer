#ifndef COLLISION_H
#define COLLISION_H

#include <SDL2/SDL_log.h>

#include "include/rectanglecollision.h"
#include "include/math/intersect.h"
#include "include/math/angle.h"
#include "include/math/distance.h"

#include <vector>

class Collision
{
public:

    Collision();

    bool IsCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> &coliders);

    void SetCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> &coliders);
private:

    void FixPosition(Vector2f intersect_position, Vector2f fixed_intersect_position, RectangleCollision *object, Vector2f object_old_position, Vector2f object_current_position, Vector2f colider_position_start, Vector2f colider_position_end);
    void MoveRectangleCollision(RectangleCollision *object, Angle angle, float distance);
    Angle GetFixedAngle(Vector2f start, Vector2f end, std::string flip_type); // flip_type = horizontal, vertical
};

#endif // COLLISION_H
