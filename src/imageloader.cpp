#include "include/imageloader.h"

ImageLoader::ImageLoader() {

}

void ImageLoader::Init(Render *render) {

    this->render = render;
}

SDL_Texture *ImageLoader::LoadImage(const char *path) {

    SDL_Surface *surface = IMG_Load(path);

    if (!surface) {

        SDL_Log("Error: cannot create surface: %s %s (ImageLoader)", path, SDL_GetError());
        return nullptr;
    }


    Uint32 alpha_color = SDL_MapRGB(surface->format, 255, 51, 204); // pink
    SDL_SetColorKey(surface, SDL_TRUE, alpha_color);

    SDL_Texture *texture = SDL_CreateTextureFromSurface(render->GetRenderer(), surface);

    if (texture == nullptr) {

        SDL_Log("Error: cannot create texture: %s %s (ImageLoader)", path, SDL_GetError());
        return nullptr;
    }

    SDL_FreeSurface(surface);

    return texture;
}
