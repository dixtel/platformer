#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>

#include "include/rectangle.h"
#include "include/gameobject.h"

#include <vector>

class Render
{
    SDL_Renderer *renderer = nullptr;
    SDL_Color     clear_color;
public:

    Render(SDL_Renderer *renderer, SDL_Color clear_color);

    void SetColorClear(SDL_Color color);
    void Clear();
    void Draw(Rectangle *rectangle);
    void Draw(std::vector<GameObject*> &gameobjects);
    void Display();

    SDL_Renderer *GetRenderer();
};

#endif // RENDER_H
