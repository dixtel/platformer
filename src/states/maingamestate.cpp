#include "include/states/maingamestate.h"

MainGameState::MainGameState(const unsigned width_state, const unsigned height_state, Vector2f viewpoint, Render *render) {

    this->viewpoint = viewpoint;
    this->render = render;
    this->width_state = width_state;
    this->height_state = height_state;

    image_loader.Init(render);
    handle_input.Init(width_state, height_state);

    game_exit = false;
    game_object_manager.CreateObject("player", new Player());
    game_object_manager.GetGameObject("player")->Init({250, 250}, {50, 50}, image_loader.LoadImage("res/textures/player.png"));
    game_object_manager.CreateObject("ground", new Ground());
    game_object_manager.GetGameObject("ground")->Init({250, 400}, {50, 50}, image_loader.LoadImage("res/textures/ground.png"));

}

MainGameState::~MainGameState() {

}

void MainGameState::UpdateState(float dt) {

    game_object_manager.GetGameObject("player")->UpdatePhysics(dt);

    if (collision.IsCollision(game_object_manager.GetGameObject("player")->GetRectangleCollision(), ))

    game_object_manager.GetGameObject("player")->Update();
}

void MainGameState::RenderState() {

    // TODO add viewpoint
    render->Clear();
    render->Draw(game_object_manager.GetGameObject("player")->GetRectangle());
    render->Draw(game_object_manager.GetGameObject("ground")->GetRectangle());
    render->Display();
}

void MainGameState::HandleEvents() {

    handle_input.Update();

    if (handle_input.IsWindowQuit()) {

        game_exit = true;
    }

    if (handle_input.IsMouseRightButton()) {

    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_RIGHT)) {

        game_object_manager.GetGameObject("player")->HandleInput(GameObjectInput::RIGHT_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_RIGHT)) {

        game_object_manager.GetGameObject("player")->HandleInput(GameObjectInput::RIGHT_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_LEFT)) {

        game_object_manager.GetGameObject("player")->HandleInput(GameObjectInput::LEFT_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_LEFT)) {

        game_object_manager.GetGameObject("player")->HandleInput(GameObjectInput::LEFT_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_UP)) {

        game_object_manager.GetGameObject("player")->HandleInput(GameObjectInput::UP_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_UP)) {

        game_object_manager.GetGameObject("player")->HandleInput(GameObjectInput::UP_ON);
    }

    // TODO Test finger on android
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
