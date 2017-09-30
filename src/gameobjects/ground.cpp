#include "include/gameobjects/ground.h"

Ground::Ground() {

}

void Ground::Init(Vector2f position, Vector2u size, SDL_Texture *texture, ImageLoader *image_loader) {

    this->position = position;
    this->size = size;

    destination_texture = {0, 0, size.x, size.y};

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetTexture(texture);
    rectangle.SetSourceTexture(destination_texture);

    rectangle_collision.Init(position, size, STATICBODY);
}

void Ground::UpdatePhysics(double dt) {

    rectangle_collision.SetPosition(position);
}

void Ground::Ground::Update() {

    position = rectangle_collision.GetPosition();

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetSourceTexture(destination_texture);
}

void Ground::HandleInput(GameObjectInput input) {

}

void Ground::SetPosition(Vector2f position) {

    this->position = position;
}

Rectangle *Ground::GetRectangle() {

    return &rectangle;
}

RectangleCollision *Ground::GetRectangleCollision() {

    return &rectangle_collision;
}

Vector2f Ground::GetPosition() {

    return position;
}

Vector2u Ground::GetSize() {

    return size;
}
