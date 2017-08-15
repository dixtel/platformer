#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL2/SDL.h>

#include "include/rectanglecollision.h"

#include "include/vectro2.h"

class Rectangle
{
    SDL_Texture *texture = nullptr;
    SDL_Rect     destination_texture;
    SDL_Rect     rectangle_rect;
    SDL_Color    fill_rect_color;

    Vector2f position;
    Vector2u size;

    bool destination_texture_set;
public:

    Rectangle();
    ~Rectangle();

    void SetPosition(Vector2f position);
    void SetSize(Vector2u size);
    void SetTexture(SDL_Texture *texture);
    void SetDestinationTexture(SDL_Rect destination);
    void SetRectColor(SDL_Color color);

    Vector2f GetPosition();
    Vector2u GetSize();
    SDL_Texture *GetTexture();
    SDL_Rect &GetRect();
    SDL_Rect &GetDestinationTexture();
    SDL_Color GetRectColor();
};

#endif // RECTANGLE_H
