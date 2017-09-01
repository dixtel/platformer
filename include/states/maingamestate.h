#ifndef MAINGAMESTATE_H
#define MAINGAMESTATE_H

#include <SDL2/SDL.h>

#include "include/gamestate.h"
#include "include/render.h"
#include "include/gameobjectmanager.h"
#include "include/imageloader.h"
#include "include/handleinput.h"
#include "include/collision.h"
#include "include/worldmap.h"
#include "include/math/deltatime.h"
#include "include/math/vector2.h"

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

    Render           *render = nullptr;
    GameObjectManager game_object_manager;
    ImageLoader       image_loader;
    HandleInput       handle_input;
    Collision         collision;
    WorldMap          worldmap;

    Vector2f          viewpoint;
    unsigned          width_state;
    unsigned          height_state;
    bool              game_exit;
};

#endif // MAINGAMESTATE_H
