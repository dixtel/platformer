#include "include/imageloader.h"

ImageLoader::ImageLoader() {

}

void ImageLoader::Init(Render *render) {

    this->render = render;
}

SDL_Texture *ImageLoader::LoadImage(const char *path) {

    SDL_Texture *texture = IMG_LoadTexture(render->GetRenderer(), path);

    if (texture == nullptr) {

        SDL_Log("Error: cannot create texture from surface: %s %s (ImageLoader)", path, SDL_GetError());
        return nullptr;
    }

    return texture;
}
