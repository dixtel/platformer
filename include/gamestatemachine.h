#ifndef GAMESTATEMACHINE_H
#define GAMESTATEMACHINE_H

#include "include/gamestate.h"

#include <map>

enum STATE_TYPE {
    GAMESTART_STATE = 1,
    MAINGAME_STATE = 2,
    PAUSE_STATE = 3
};

class GameStateMachine
{
public:

    GameStateMachine();
    ~GameStateMachine();

    void PushBack(STATE_TYPE state_name, GameState *state);
    void ChangeState(STATE_TYPE state_name);
    void Update(float dt);
    void Render();
    void HandleEvents();
    bool IsGameExit();
private:

    // [state type], [state pointer]
    std::map<int, GameState*> game_states;
    STATE_TYPE                current_game_state;
};

#endif // GAMESTATEMACHINE_H
