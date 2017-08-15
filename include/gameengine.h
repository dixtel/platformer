#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "include/window.h"
#include "include/render.h"
#include "include/gamestatemachine.h"
#include "include/states/maingamestate.h"

class GameEngine
{
public:

    GameEngine();
    ~GameEngine();

    bool Init();
    void CleanUp();

    void Start();
private:

    bool InitGame();
    bool InitSDL();
    bool InitStates();

    Window window;
    Render *render = nullptr;
    GameStateMachine game_state_machine;

    std::string title;
    unsigned width_window;
    unsigned height_window;

    bool running;
};

#endif // GAMEENGINE_H
