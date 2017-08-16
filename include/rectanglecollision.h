#ifndef RECTANGLECOLLISION_H
#define RECTANGLECOLLISION_H

#include "include/vectro2.h"

namespace CollisionType {
enum Type {
    STATICBODY = 1,        // e.g ground, walls
    RIGHTBODY = 2,         // e.g player, enemies...
    KINEMATICBODY = 3      // e.g decoration, animation..
};
}

class RectangleCollision
{
friend class Collision;
public:

    RectangleCollision();

    void Init(Vector2f position, Vector2u size, CollisionType::Type collision_type);

    void SetPosition(Vector2f position);
    void SetSize(Vector2u size);

    CollisionType::Type GetCollisionType();
    Vector2f GetPosition();
    Vector2f GetCurrentPoint(char point);
    Vector2f GetOldPoint(char point);
private:

    void SetCollisionPosition(Vector2f position);
protected:


    CollisionType::Type collision_type;
    Vector2f current_position;
    Vector2f old_position;
    Vector2u size;

    Vector2f current_point_a;                   // A --- B
    Vector2f current_point_b;                   // D --- C
    Vector2f current_point_c;
    Vector2f current_point_d;

    Vector2f old_point_a;
    Vector2f old_point_b;
    Vector2f old_point_c;
    Vector2f old_point_d;

    void Update();
};

#endif // RECTANGLECOLLISION_H
