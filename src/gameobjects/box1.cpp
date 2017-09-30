#include "include/gameobjects/box1.h"

Box1::Box1() {

    physics_mode = true;
    velocity = {0, 0};
}

void Box1::Init(Vector2f position, Vector2u size, SDL_Texture *texture, ImageLoader *image_loader) {

    this->position = position;
    this->size = size;

    gravity  = 6;
    friction = 3.5;

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetTexture(texture);
    rectangle.SetSourceTexture({0, 0, size.x, size.y});

    rectangle_collision.Init(position, size, RIGHTBODY);
}

void Box1::UpdatePhysics(double dt) {

    if (physics_mode) {

        velocity.y += gravity * dt;

        if (velocity.x > 0) {

            velocity.x -= friction * dt;

            if (velocity.x < 0) {

                velocity.x = 0;
            }
        }
        else if (velocity.x < 0) {

            velocity.x += friction * dt;

            if (velocity.x > 0) {

                velocity.x = 0;
            }
        }
    }


    velocity.x *= rectangle_collision.GetDecreasedXVelocityProcent();
    velocity.y *= rectangle_collision.GetDecreasedYVelocityProcent();

    if (rectangle_collision.GetCollisionXAxsis()) {

        velocity.x = 0;
    }

    if (rectangle_collision.GetCollisionYAxsis()) {

        velocity.y = 0;
    }

    position += velocity;
    rectangle_collision.SetPosition(position);

   // SDL_Log("box vel xy: %f %f", velocity.x, velocity.y);
}

void Box1::Update() {

    position = rectangle_collision.GetPosition();
    rectangle.SetPosition(position);
}

void Box1::HandleInput(GameObjectInput input) {

}

void Box1::DisablePhysics() {

    physics_mode = false;
}

void Box1::EnablePhysics() {

    physics_mode = true;
}

void Box1::SetPosition(Vector2f position) {

    this->position = position;
}

void Box1::SetVelocity(Vector2f velocity) {

    this->velocity = velocity;
}

Rectangle *Box1::GetRectangle() {

    return &rectangle;
}

RectangleCollision *Box1::GetRectangleCollision() {

    return &rectangle_collision;
}

Vector2f Box1::GetPosition() {

    return rectangle.GetPosition();
}

Vector2u Box1::GetSize() {

    return rectangle.GetSize();
}
