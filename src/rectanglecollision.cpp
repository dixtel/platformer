#include "include/rectanglecollision.h"

RectangleCollision::RectangleCollision() {

    is_collision_x_axsis = false;
    is_collision_y_axsis = false;
    current_position = {0, 0};
    old_position = {0, 0};
    center = {0, 0};
}

void RectangleCollision::Init(Vector2f position, Vector2u size, CollisionType collision_type) {

    this->size = size;
    this->collision_type = collision_type;
    old_position = position;
    current_position = position;
    point_A = point_B = point_C = point_D = position;
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

void RectangleCollision::Move(Vector2f move_distance) {

    current_position += move_distance;
    old_position = current_position;
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

Vector2f RectangleCollision::GetPointPosition(char point) {

    switch (point) {
    case 'A':

        return point_A;
    case 'B':

        return point_B;
    case 'C':

        return point_C;
    case 'D':

        return point_D;
    default:

        return {0, 0};
    }
}

Vector2f RectangleCollision::GetCenterPosition() {

    return center;
}

void RectangleCollision::Update() {

    point_A = current_position;
    point_B = current_position + Vector2f {size.x, 0};
    point_C = current_position + Vector2f {size.x, size.y};
    point_D = current_position + Vector2f {0, size.y};
    center = Vector2f(current_position.x + (size.x / 2), current_position.y + (size.y / 2));
}
