#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

#include "include/rectangle.h"

class Render
{
    SDL_Renderer *renderer = nullptr;
    SDL_Color clear_color;
public:

    Render(SDL_Renderer *renderer, SDL_Color clear_color);

    void SetColorClear(SDL_Color color);
    void Clear();
    void Draw(Rectangle *rectangle);
    void Display();

    SDL_Renderer *GetRenderer();
};

#endif // RENDER_H
