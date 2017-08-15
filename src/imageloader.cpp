#include "include/imageloader.h"

ImageLoader::ImageLoader() {

}

SDL_Texture *ImageLoader::LoadImage(char *path) {

    SDL_Surface *surface = IMG_Load(path);

    if (surface == nullptr) {

        SDL_Log("Error: cannot load image: %s (ImageLoader)", path);
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(render-, surface);

    if (texture == nullptr) {

        SDL_FreeSurface(surface);
        SDL_Log("Error: cannot create texture from surface: %s (ImageLoader)", path);
        return nullptr;
    }

    return texture;
}
