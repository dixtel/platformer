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

    GameObject *player = game_object_manager.GetGameObject("player", "1");
    std::vector<GameObject*> boxses_1 = game_object_manager.GetGroupObjects("box1");

    player->UpdatePhysics(dt);

    for (int i = 0; i < boxses_1.size(); ++i)
        boxses_1[i]->UpdatePhysics(dt);

    if (player->IsBringGameObject()) {

        if (collision.IsCollision(player->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("ground"))
                || collision.IsCollision(player->GetBringerGameObject()->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("ground")))
            collision.SetCollision(player->GetRectangleCollision(), player->GetBringerGameObject()->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("ground"));
    }
    else {

        if (collision.IsCollision(player->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("ground")))
            collision.SetCollision(player->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("ground"));

        for (int j = 0; j < boxses_1.size(); ++j) {

            if (collision.IsCollision(boxses_1[j]->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("ground")))
                collision.SetCollision(boxses_1[j]->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("ground"));
        }

        if (collision.IsCollision(player->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("box1")))
            collision.SetCollision(player->GetRectangleCollision(), game_object_manager.GetGroupObjectsAsRectangleCollision("box1"));
    }

    if (collision.IsCollision(player->GetRectangleCollision(), game_object_manager.GetGameObject("end_map", "1")->GetRectangleCollision())) {

        SDL_Log("end map");
    }

    player->Update();

    for (int i = 0; i < boxses_1.size(); ++i)
        boxses_1[i]->Update();

    // bring objects around player
    if (player->IsBringState()) {

        for (int i = 0; i < boxses_1.size(); ++i)
            player->Bring(boxses_1[i]);
    }

    render->SetView(player->GetRectangle()->GetPosition() - Vector2f(460, 320), Vector2u(960, 640));
}

void MainGameState::RenderState() {

    render->Clear();
    render->Draw(game_object_manager.GetGameObjectsByLayer("down"));
    render->Draw(game_object_manager.GetGameObjectsByLayer("middle"));
    render->Draw(game_object_manager.GetGameObjectsByLayer("top"));
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

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::RIGHT_OFF);
    }

    else if (handle_input.IsKeyUp(SDL_SCANCODE_RIGHT)) {

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::RIGHT_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_LEFT)) {

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::LEFT_OFF);
    }

    else if (handle_input.IsKeyUp(SDL_SCANCODE_LEFT)) {

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::LEFT_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_UP)) {

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::UP_OFF);
    }

    else if (handle_input.IsKeyUp(SDL_SCANCODE_UP)) {

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::UP_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_DOWN)) {

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::DOWN_OFF);
    }

    else if (handle_input.IsKeyUp(SDL_SCANCODE_DOWN)) {

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::DOWN_ON);
    }

    if (handle_input.IsKeyDown(SDL_SCANCODE_SPACE)) {

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::SPACEBAR_OFF);
    }

    else if (handle_input.IsKeyUp(SDL_SCANCODE_SPACE)) {

        game_object_manager.GetGameObject("player", "1")->HandleInput(GameObjectInput::SPACEBAR_ON);
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
