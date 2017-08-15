#include "include/rectangle.h"

Rectangle::Rectangle() {

    fill_rect_color = {255, 0, 0, 255};
    destination_texture_set = false;
}

Rectangle::~Rectangle() {

    if (texture) {

        SDL_DestroyTexture(texture);
    }
}

void Rectangle::SetPosition(Vector2f position) {

    this->position = position;

    rectangle_rect.x = position.x;
    rectangle_rect.y = position.y;
}

void Rectangle::SetSize(Vector2u size) {

    this->size = size;

    rectangle_rect.w = size.x;
    rectangle_rect.h = size.y;

    if (destination_texture_set == false) {

        destination_texture = {0, 0, size.x, size.y};
    }
}

void Rectangle::SetTexture(SDL_Texture *texture) {

    if (texture) {

        SDL_DestroyTexture(texture);
    }

    this->texture = texture;
}

void Rectangle::SetDestinationTexture(SDL_Rect destination) {

    destination_texture = destination;
    destination_texture_set = true;
}

void Rectangle::SetRectColor(SDL_Color color) {

    this->fill_rect_color = color;
}


Vector2f Rectangle::GetPosition() {

    return position;
}

Vector2u Rectangle::GetSize() {

    return size;
}

SDL_Texture *Rectangle::GetTexture() {

    return texture;
}

SDL_Rect &Rectangle::GetRect() {

    return rectangle_rect;
}

SDL_Rect &Rectangle::GetDestinationTexture() {

    return destination_texture;
}

SDL_Color Rectangle::GetRectColor() {

    return fill_rect_color;
}
