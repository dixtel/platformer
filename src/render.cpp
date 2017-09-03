#include "include/render.h"

Render::Render(SDL_Renderer *renderer, SDL_Color clear_color) {

    this->renderer = renderer;
    this->clear_color = clear_color;
    view = {0, 0, 0, 0};

    SDL_SetRenderDrawColor(renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a);
}

void Render::SetColorClear(SDL_Color color) {

    clear_color = color;
    SDL_SetRenderDrawColor(renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a);
}

void Render::SetView(Vector2f position, Vector2u size) {

    view = {position.x, position.y, size.x, size.y};
}

void Render::Clear() {

    SDL_RenderClear(renderer);
}

void Render::Draw(Rectangle *rectangle) {

    if (!rectangle) {

        SDL_Log("Error: rectangle to draw are NULL (Render)");
        return;
    }

    SDL_Rect fixed_position = {rectangle->GetPosition().x - view.x, rectangle->GetPosition().y - view.y, rectangle->GetRectDestination().w, rectangle->GetRectDestination().h};

    SDL_SetRenderDrawColor(renderer, rectangle->GetRectColor().r, rectangle->GetRectColor().g, rectangle->GetRectColor().b, rectangle->GetRectColor().a);
    SDL_RenderFillRect(renderer, &fixed_position);
    SDL_SetRenderDrawColor(renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a);
    SDL_RenderCopy(renderer,
                   rectangle->GetTexture(),
                   &rectangle->GetSourceTexture(),
                   &fixed_position);
}

void Render::Draw(std::vector<GameObject*> &gameobjects) {

    for (std::vector<GameObject*>::iterator it = gameobjects.begin(); it != gameobjects.end(); ++it) {

        Draw((*it)->GetRectangle());
    }
}

void Render::Display() {

    SDL_RenderPresent(renderer);
}

SDL_Renderer *Render::GetRenderer() {

    return renderer;
}

