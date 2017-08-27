#include "include/states/maingamestate.h"

MainGameState::MainGameState(const unsigned width_state, const unsigned height_state, Vector2f viewpoint, Render *render) {

    this->viewpoint = viewpoint;
    this->render = render;
    this->width_state = width_state;
    this->height_state = height_state;

    image_loader.Init(render);
    handle_input.Init(width_state, height_state);

    game_exit = false;
    game_object_manager.CreateObject("players", "player", new Player());
    game_object_manager.GetGameObject("players", "player")->Init({460, 250}, {50, 50}, image_loader.LoadImage("res/textures/player.png"));

    game_object_manager.CreateObject("grounds", "ground_1", new Ground());
    game_object_manager.GetGameObject("grounds", "ground_1")->Init({300, 300}, {100, 100}, NULL);
}

MainGameState::~MainGameState() {

}

void MainGameState::UpdateState(float dt) {

    game_object_manager.GetGameObject("players", "player")->UpdatePhysics(dt);

    if (collision.IsCollision(game_object_manager.GetGameObject("players", "player")->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("grounds"))) {

        collision.SetCollision(game_object_manager.GetGameObject("players", "player")->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("grounds"));
    }

    game_object_manager.GetGameObject("players", "player")->Update();
}

void MainGameState::RenderState() {

    // TODO add viewpoint
    render->Clear();
    // TODO change this to get by groups
    render->Draw(game_object_manager.GetGameObject("players", "player")->GetRectangle());
    render->Draw(game_object_manager.GetGameObject("grounds", "ground_1")->GetRectangle());
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

        game_object_manager.GetGameObject("players", "player")->HandleInput(GameObjectInput::RIGHT_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_RIGHT)) {

        game_object_manager.GetGameObject("players", "player")->HandleInput(GameObjectInput::RIGHT_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_LEFT)) {

        game_object_manager.GetGameObject("players", "player")->HandleInput(GameObjectInput::LEFT_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_LEFT)) {

        game_object_manager.GetGameObject("players", "player")->HandleInput(GameObjectInput::LEFT_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_UP)) {

        game_object_manager.GetGameObject("players", "player")->HandleInput(GameObjectInput::UP_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_UP)) {

        game_object_manager.GetGameObject("players", "player")->HandleInput(GameObjectInput::UP_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_DOWN)) {

        game_object_manager.GetGameObject("players", "player")->HandleInput(GameObjectInput::DOWN_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_DOWN)) {

        game_object_manager.GetGameObject("players", "player")->HandleInput(GameObjectInput::DOWN_ON);
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
