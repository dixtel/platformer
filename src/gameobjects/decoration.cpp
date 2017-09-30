#include "include/gameobjects/decoration.h"

Decoration::Decoration()
{

}

void Decoration::Init(Vector2f position, Vector2u size, SDL_Texture *texture, ImageLoader *image_loader) {

    this->position = position;
    this->size = size;

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetTexture(texture);
    rectangle.SetSourceTexture({0, 0, size.x, size.y});

    rectangle_collision.Init(position, size, RIGHTBODY);
}

void Decoration::UpdatePhysics(double dt) {

}

void Decoration::Update() {

}

void Decoration::HandleInput(GameObjectInput input) {

}

void Decoration::SetPosition(Vector2f position) {

    this->position = position;
}

Rectangle *Decoration::GetRectangle() {

    return &rectangle;
}

RectangleCollision *Decoration::GetRectangleCollision() {

    return &rectangle_collision;
}

Vector2f Decoration::GetPosition() {

    return position;
}

Vector2u Decoration::GetSize() {

    return size;
}
