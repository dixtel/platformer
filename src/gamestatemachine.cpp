#include "include/gamestatemachine.h"

GameStateMachine::GameStateMachine() {

}

GameStateMachine::~GameStateMachine() {

    for (int i = 0; i < game_states.size(); ++i) {

        delete game_states[i];
        game_states[i] = nullptr;
    }
}

void GameStateMachine::PushBack(STATE_TYPE state_name, GameState *state) {

    std::map<int, GameState*>::iterator it;
    it = game_states.find(state_name);

    if (it != game_states.end()) {

        delete it->second;
        game_states.erase(it);
    }

    game_states[state_name] = state;
}

void GameStateMachine::ChangeState(STATE_TYPE state_name) {

    game_states[current_game_state]->OnExit();
    current_game_state = state_name;
    game_states[current_game_state]->OnEnter();
}

void GameStateMachine::Update(float dt) {

    game_states[current_game_state]->UpdateState(dt);
}

void GameStateMachine::Render() {

    game_states[current_game_state]->RenderState();
}

void GameStateMachine::HandleEvents() {

    game_states[current_game_state]->HandleEvents();
}

bool GameStateMachine::IsGameExit() {

    return game_states[current_game_state]->IsGameExit();
}
