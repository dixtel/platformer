#include "include/states/maingamestate.h"

MainGameState::MainGameState(const unsigned state_width, const unsigned state_height, Vector2f viewpoint, Render *render) {

    this->viewpoint = viewpoint;
    this->render = render;
    this->width_state = width_state;
    this->height_state = height_state;

    game_exit = false;
    game_object_manager.CreateObject("player", Player());
    game_object_manager.GetGameObject("player")->Init({250, 250}, {50, 50}, );
}

MainGameState::~MainGameState() {

    render = nullptr;
}

void MainGameState::UpdateState(float dt) {

}

void MainGameState::RenderState() {

    render->Clear();
    render->Display();
}

void MainGameState::HandleEvents() {

}

void MainGameState::OnEnter() {

    SDL_Log("Enter to MainGameState");
}

void MainGameState::OnExit() {

    SDL_Log("Leave to MainGameState");
}

bool MainGameState::IsGameExit() {

    return game_exit;
}
