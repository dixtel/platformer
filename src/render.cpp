#include "include/render.h"

Render::Render(SDL_Renderer *renderer, SDL_Color clear_color) {

    this->renderer = renderer;
    this->clear_color = clear_color;
    SDL_SetRenderDrawColor(renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a);
}

void Render::SetColorClear(SDL_Color color) {

    clear_color = color;
    SDL_SetRenderDrawColor(renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a);
}

void Render::Clear() {

    SDL_RenderClear(renderer);
}

void Render::Draw(Rectangle *rectangle) {

    SDL_SetRenderDrawColor(renderer, rectangle->GetRectColor().r, rectangle->GetRectColor().g, rectangle->GetRectColor().b, rectangle->GetRectColor().a);
    SDL_RenderFillRect(renderer, &rectangle->GetRect());
    SDL_SetRenderDrawColor(renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a);
    SDL_RenderCopy(renderer,
                   rectangle->GetTexture(),
                   &rectangle->GetRect(),
                   &rectangle->GetDestinationTexture());
}

void Render::Display() {

    SDL_RenderPresent(renderer);
}

SDL_Renderer *Render::GetRenderer() {

    return renderer;
}

