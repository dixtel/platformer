#ifndef RECTANGLECOLLISION_H
#define RECTANGLECOLLISION_H

#include "include/vectro2.h"

class RectangleCollision
{
friend class Collision;
public:

    RectangleCollision();

    void SetPosition(Vector2f position);
    void SetSize(Vector2u size);

    Vector2f GetPosition();
    Vector2f GetCurrentPoint(char point);
    Vector2f GetOldPoint(char point);
private:

    void SetCollisionPosition(Vector2f position);
protected:

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
