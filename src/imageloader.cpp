#include "include/imageloader.h"

ImageLoader::ImageLoader() {

}

void ImageLoader::Init(Render *render) {

    this->render = render;
}

SDL_Texture *ImageLoader::LoadImage(char *path) {

    SDL_Surface *surface = IMG_Load(path);

    if (surface == nullptr) {

        SDL_Log("Error: cannot load image: %s %s (ImageLoader)", path, SDL_GetError());
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(render->GetRenderer(), surface);

    if (texture == nullptr) {

        SDL_FreeSurface(surface);
        SDL_Log("Error: cannot create texture from surface: %s %s (ImageLoader)", path, SDL_GetError());
        return nullptr;
    }

    return texture;
}
