#ifndef HANDLEINPUT_H
#define HANDLEINPUT_H

#include "SDL2/SDL.h"

#include "include/math/vector2.h"

class HandleInput
{
public:

    HandleInput();

    void Init(unsigned screen_width, unsigned screen_height);
    void Update();

    bool IsKeyUp(SDL_Scancode key);
    bool IsKeyDown(SDL_Scancode key);
    bool IsFingerDown();
    bool IsFingerUp();
    bool IsFigerMotion();
    bool IsMouseLeftButton();
    bool IsMouseRightButton();
    bool IsMouseMiddleButton();
    bool IsWindowQuit();

    Vector2i GetMousePosition();
    Vector2f GetTouchPosition();
private:

    SDL_Event event;
    const Uint8 *key_state = SDL_GetKeyboardState(NULL);
    Vector2i mouse_position;
    Vector2f touch_position;

    bool button_left;
    bool button_right;
    bool button_middle;
    bool touch_down;
    bool touch_up;
    bool touch_motion;
    bool window_quit;

    unsigned screen_width;
    unsigned screen_height;
};

#endif // HANDLEINPUT_H
