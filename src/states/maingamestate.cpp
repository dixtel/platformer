#include "include/states/maingamestate.h"

MainGameState::MainGameState(const unsigned width_state, const unsigned height_state, Vector2f viewpoint, Render *render) {

    this->viewpoint = viewpoint;
    this->render = render;
    this->width_state = width_state;
    this->height_state = height_state;

    image_loader.Init(render);

    game_exit = false;
    game_object_manager.CreateObject("player", new Player());
    game_object_manager.GetGameObject("player")->Init({250, 250}, {50, 50}, image_loader.LoadImage("res/textures/player.png"));
    game_object_manager.CreateObject("ground", new Ground());
    game_object_manager.GetGameObject("ground")->Init({250, 400}, {50, 50}, image_loader.LoadImage("res/textures/ground.png"));

}

MainGameState::~MainGameState() {

    render = nullptr;
}

void MainGameState::UpdateState(float dt) {

}

void MainGameState::RenderState() {

    // TODO add viewpoint
    render->Clear();
    render->Draw(game_object_manager.GetGameObject("player")->GetRectangle());
    render->Draw(game_object_manager.GetGameObject("ground")->GetRectangle());
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
