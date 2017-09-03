#include "include/states/maingamestate.h"

MainGameState::MainGameState(const unsigned width_state, const unsigned height_state, Vector2f viewpoint, Render *render) {

    this->viewpoint = viewpoint;
    this->render = render;
    this->width_state = width_state;
    this->height_state = height_state;
    game_exit = false;

    image_loader.Init(render);
    handle_input.Init(width_state, height_state);
    worldmap.Init("res/maps/", &image_loader);

    worldmap.AddMap("map_1.tmx", "tilessets.tsx");
    worldmap.CreateObjectsMap("map_1.tmx", &game_object_manager);
}

MainGameState::~MainGameState() {

}

void MainGameState::UpdateState(float dt) {

    GameObject *player = game_object_manager.GetGameObject("Player", "1");

    player->UpdatePhysics(dt);

    if (collision.IsCollision(player->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("Ground"))) {

        collision.SetCollision(player->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("Ground"));
    }

    player->Update();

    render->SetView(player->GetRectangle()->GetPosition() - Vector2f(460, 320), Vector2u(960, 640));
}

void MainGameState::RenderState() {

    // TODO add viewpoint
    render->Clear();
    render->Draw(game_object_manager.GetGameObjectsByLayer("Down"));
    render->Draw(game_object_manager.GetGameObjectsByLayer("Middle"));
    render->Draw(game_object_manager.GetGameObjectsByLayer("Top"));
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

        game_object_manager.GetGameObject("Player", "1")->HandleInput(GameObjectInput::RIGHT_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_RIGHT)) {

        game_object_manager.GetGameObject("Player", "1")->HandleInput(GameObjectInput::RIGHT_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_LEFT)) {

        game_object_manager.GetGameObject("Player", "1")->HandleInput(GameObjectInput::LEFT_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_LEFT)) {

        game_object_manager.GetGameObject("Player", "1")->HandleInput(GameObjectInput::LEFT_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_UP)) {

        game_object_manager.GetGameObject("Player", "1")->HandleInput(GameObjectInput::UP_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_UP)) {

        game_object_manager.GetGameObject("Player", "1")->HandleInput(GameObjectInput::UP_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_DOWN)) {

        game_object_manager.GetGameObject("Player", "1")->HandleInput(GameObjectInput::DOWN_OFF);
    }

    if (handle_input.IsKeyUp(SDL_SCANCODE_DOWN)) {

        game_object_manager.GetGameObject("Player", "1")->HandleInput(GameObjectInput::DOWN_ON);
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
