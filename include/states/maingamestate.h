#ifndef MAINGAMESTATE_H
#define MAINGAMESTATE_H

#include <SDL2/SDL.h>

#include "include/gamestate.h"
#include "include/render.h"
#include "include/vectro2.h"
#include "include/gameobjectmanager.h"

class MainGameState : public GameState
{
public:

    MainGameState(const unsigned width_state, const unsigned height_state, Vector2f viewpoint, Render *render);
    ~MainGameState();

    void UpdateState(float dt);
    void RenderState();
    void HandleEvents();
    void OnEnter();
    void OnExit();
    bool IsGameExit();
private:

    Render *render = nullptr;
    GameObjectManager game_object_manager;

    Vector2f viewpoint;
    unsigned width_state;
    unsigned height_state;

    bool game_exit;
};

#endif // MAINGAMESTATE_H
