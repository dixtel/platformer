#include "include/gameengine.h"

int main(int argc, char* argv[]) {

    GameEngine game_engine;

    if (!game_engine.Init()) {

        return 1;
    }

    game_engine.Start();
    game_engine.CleanUp();

    return 0;
}
