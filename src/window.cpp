#include "include/window.h"

Window::Window() {

}

Window::~Window() {

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

bool Window::Init(const std::string title, int x, int y, int w, int h, Uint32 window_flags, Uint32 renderer_flags) {

    window = SDL_CreateWindow(title.c_str(), x, y , w , h, window_flags);

    if (window == NULL) {

        SDL_Log("Error while creating window: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, renderer_flags);

    if (renderer == NULL) {

        SDL_Log("Error while creating renderer: %s", SDL_GetError());
        return false;
    }

    return true;
}


SDL_Renderer *Window::GetRenderer() {

    return renderer;
}
