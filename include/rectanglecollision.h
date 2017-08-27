#ifndef RECTANGLECOLLISION_H
#define RECTANGLECOLLISION_H

#include "include/math/vector2.h"

enum CollisionType {
    STATICBODY,         // e.g ground, walls
    RIGHTBODY,          // e.g player, enemies...
    KINEMATICBODY       // e.g decoration, animation..
};

class RectangleCollision
{
friend class Collision;
public:

    RectangleCollision();

    void Init(Vector2f position, Vector2u size, CollisionType collision_type);

    void SetPosition(Vector2f position);
    void SetSize(Vector2u size);

    bool GetCollisionXAxsis();
    bool GetCollisionYAxsis();

    Vector2f GetPosition();
private:

    void SetCollisionPosition(Vector2f position);

    void EnableCollisionXAxsis();
    void EnableCollisionYAxsis();

    void Move(Vector2f move_distance);

    CollisionType GetCollisionType();
    Vector2u GetSize();
    Vector2f GetPointPosition(char point);
    Vector2f GetCenterPosition();
protected:

    bool is_collision_x_axsis;
    bool is_collision_y_axsis;

    CollisionType collision_type;
    Vector2f current_position;
    Vector2f old_position;
    Vector2u size;

    Vector2f point_a;                   // A --- B
    Vector2f point_b;                   // D --- C
    Vector2f point_c;
    Vector2f point_d;
    Vector2f center;

    void Update();
};

#endif // RECTANGLECOLLISION_H
