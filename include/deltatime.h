#ifndef DELTATIME_H
#define DELTATIME_H

#include <SDL2/SDL.h>

struct DeltaTime {

    Uint64 current_time;
    Uint64 last_time;

    DeltaTime() {

        current_time = SDL_GetPerformanceCounter();
        last_time = 0;
    }

    double GetDeltaTime() {

        last_time = current_time;
        current_time = SDL_GetPerformanceCounter();

        return (double)(current_time - last_time) * 1000 / SDL_GetPerformanceFrequency() / 1000;
    }
};

#endif // DELTATIME_H
