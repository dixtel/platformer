#include "include/rectanglecollision.h"

RectangleCollision::RectangleCollision() {

    is_collision_x_axsis = false;
    is_collision_y_axsis = false;
    current_position = {0, 0};
    old_position = {0, 0};
}

void RectangleCollision::Init(Vector2f position, Vector2u size, CollisionType collision_type) {

    this->size = size;
    this->collision_type = collision_type;
    old_position = position;
    current_position = position;
    old_point_a = old_point_b = old_point_c = old_point_d
            = current_point_a = current_point_b = current_point_c = current_point_d
            = position;
    Update();
}

void RectangleCollision::SetPosition(Vector2f position) {

    old_position = current_position;
    current_position = position;
    Update();
}

void RectangleCollision::SetSize(Vector2u size) {

    this->size = size;
    Update();
}

bool RectangleCollision::GetCollisionXAxsis() {

    if (is_collision_x_axsis) {

        is_collision_x_axsis = false;
        return true;
    }

    return false;
}

bool RectangleCollision::GetCollisionYAxsis() {

    if (is_collision_y_axsis) {

        is_collision_y_axsis = false;
        return true;
    }

    return false;
}

Vector2f RectangleCollision::GetPosition() {

    return current_position;
}

void RectangleCollision::SetCollisionPosition(Vector2f position) {

    old_position = position;
    current_position = position;
    Update();
}

void RectangleCollision::SetCurrentPosition(Vector2f position) {

    current_position = position;
    Update();
}

void RectangleCollision::EnableCollisionXAxsis() {

    is_collision_x_axsis = true;
}

void RectangleCollision::EnableCollisionYAxsis() {

    is_collision_y_axsis = true;
}

CollisionType RectangleCollision::GetCollisionType() {

    return collision_type;
}

Vector2u RectangleCollision::GetSize() {

    return size;
}

Vector2f &RectangleCollision::GetCurrentPoint(char point) {

    static Vector2f nothing = {0, 0};

    switch (point) {
    case 'A':

        return current_point_a;
    case 'B':

        return current_point_b;
    case 'C':

        return current_point_c;
    case 'D':

        return current_point_d;
    default:

        return nothing;
    }
}

Vector2f &RectangleCollision::GetOldPoint(char point) {

    static Vector2f nothing = {0, 0};

    switch (point) {
    case 'A':

        return old_point_a;
    case 'B':

        return old_point_b;
    case 'C':

        return old_point_c;
    case 'D':

        return old_point_d;
    default:

        return nothing;
    }
}

void RectangleCollision::Update() {

    old_point_a = current_point_a;
    old_point_b = current_point_b;
    old_point_c = current_point_c;
    old_point_d = current_point_d;

    current_point_a = current_position;
    current_point_b = current_position + Vector2f {size.x, 0};
    current_point_c = current_position + Vector2f {size.x, size.y};
    current_point_d = current_position + Vector2f {0, size.y};
}
