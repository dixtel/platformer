#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "include/render.h"

class ImageLoader
{
public:

    ImageLoader();

    void Init(Render *render);
    SDL_Texture *LoadImage(char *path);
private:

    Render *render = nullptr;
};

#endif // IMAGELOADER_H
