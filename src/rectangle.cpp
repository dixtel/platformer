#include "include/rectangle.h"

Rectangle::Rectangle() {

    fill_rect_color = {255, 0, 0, 255};
    source_texture_set = false;
}

Rectangle::~Rectangle() {

    if (texture) {

        SDL_DestroyTexture(texture);
    }
}

void Rectangle::SetPosition(Vector2f position) {

    this->position = position;

    destination_rectangle.x = position.x;
    destination_rectangle.y = position.y;
}

void Rectangle::SetSize(Vector2u size) {

    this->size = size;

    destination_rectangle.w = size.x;
    destination_rectangle.h = size.y;

    if (source_texture_set == false) {

        source_texture = {0, 0, size.x, size.y};
    }
}

void Rectangle::SetTexture(SDL_Texture *texture) {

    if (this->texture) {

        SDL_DestroyTexture(texture);
    }

    this->texture = texture;
}

void Rectangle::SetSourceTexture(SDL_Rect destination) {

    source_texture = destination;
    source_texture_set = true;
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

SDL_Rect &Rectangle::GetRectDestination() {

    return destination_rectangle;
}

SDL_Rect &Rectangle::GetSourceTexture() {

    return source_texture;
}

SDL_Color Rectangle::GetRectColor() {

    return fill_rect_color;
}
