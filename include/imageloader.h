#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ImageLoader
{
public:

    ~ImageLoader();

    void Init(SDL_Renderer *renderer);
    SDL_Texture *LoadTexture(const char *path);
    SDL_Surface *LoadSurface(const char *path);

    SDL_Texture *ConvertSurfaceToTexture(SDL_Surface *surface);
private:

    SDL_Renderer *renderer = nullptr;
};

#endif // IMAGELOADER_H
