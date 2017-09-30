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
    bool GetCollisionYAxsisDown();
    float GetDecreasedXVelocityProcent();
    float GetDecreasedYVelocityProcent();

    Vector2f GetPosition();
private:

    void SetCollisionPosition(Vector2f position);
    void Move(Vector2f move_distance);
    void EnableCollisionXAxsis();
    void EnableCollisionYAxsis();
    void EnableCollisionYAxsisDown();
    void DecreaseXVelocity(float procent);
    void DecreaseYVelocity(float procent);

    CollisionType GetCollisionType();
    Vector2u GetSize();
    Vector2f GetPointPosition(char point);
    Vector2f GetCenterPosition();
protected:

    void Update();

    bool           is_collision_x_axsis;
    bool           is_collision_y_axsis;
    bool           is_collision_y_axsis_down;

    float          decrease_x_velocity_procent;
    float          decrease_y_velocity_procent;

    CollisionType  collision_type;
    Vector2f       current_position;
    Vector2f       old_position;
    Vector2u       size;


    // A = left up corner, B = right up corner, C = right down corner, D = left down corner
    Vector2f       point_A;
    Vector2f       point_B;
    Vector2f       point_C;
    Vector2f       point_D;
    Vector2f       center;
};

#endif // RECTANGLECOLLISION_H
