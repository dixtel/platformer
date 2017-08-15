#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#include "include/vectro2.h"

#include <string>

class Window
{
    SDL_Window   *window = nullptr;
    SDL_Renderer *renderer = nullptr;
public:

    Window();
    ~Window();

    bool Init(const std::string title, int x, int y, int w, int h, Uint32 window_lags, Uint32 renderer_flags);

    SDL_Renderer *GetRenderer();
};

#endif // WINDOW_H
