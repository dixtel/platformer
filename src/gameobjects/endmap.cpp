#include "include/gameobjects/endmap.h"

EndMap::EndMap()
{

}

void EndMap::Init(Vector2f position, Vector2u size, SDL_Texture *texture, ImageLoader *image_loader) {

    this->position = position;
    this->size = size;

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetTexture(texture);
    rectangle.SetSourceTexture({0, 0, size.x, size.y});

    rectangle_collision.Init(position, size, KINEMATICBODY);
}

void EndMap::UpdatePhysics(double dt) {

}

void EndMap::Update() {

}

void EndMap::HandleInput(GameObjectInput input) {

}

void EndMap::SetPosition(Vector2f position) {

    this->position = position;
}

Rectangle *EndMap::GetRectangle() {

    return &rectangle;
}

RectangleCollision *EndMap::GetRectangleCollision() {

    return &rectangle_collision;
}

Vector2f EndMap::GetPosition() {

    return position;
}

Vector2u EndMap::GetSize() {

    return size;
}
