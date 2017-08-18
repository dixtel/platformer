#include "include/handleinput.h"

HandleInput::HandleInput() {

    button_left = false;
    button_right = false;
    button_middle = false;
    touch_down = false;
    touch_up = false;
    touch_motion = false;
    window_quit = false;
    screen_width = 0;
    screen_height = 0;
}

void HandleInput::Init(unsigned screen_width, unsigned screen_height) {

    this->screen_width = screen_width;
    this->screen_height = screen_height;
}

void HandleInput::Update() {

    SDL_PumpEvents();
    SDL_GetMouseState(&mouse_position.x, &mouse_position.y);

    if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
        button_left = true;
    else
        button_left = false;


    if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_RIGHT))
        button_right = true;
    else
        button_right = false;


    if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_MIDDLE))
        button_middle = true;
    else
        button_middle = false;

    while (SDL_PollEvent(&event)) {

        if (event.type == SDL_QUIT)
            window_quit = true;

        if (event.type == SDL_FINGERDOWN) {
            touch_position = {event.tfinger.x * screen_width, event.tfinger.y * screen_height};
            touch_down = true;
        }
        else
            touch_down = false;

        if (event.type == SDL_FINGERUP) {

            touch_position = {event.tfinger.x * screen_width, event.tfinger.y * screen_height};
            touch_up = true;
        }
        else
            touch_up = false;

        if (event.type == SDL_FINGERMOTION) {

            touch_motion = true;
            touch_position = {event.tfinger.x * screen_width, event.tfinger.y * screen_height};
        }
        else
            touch_motion = false;
    }

}

bool HandleInput::IsKeyUp(SDL_Scancode key) {

    return key_state[key];
}

bool HandleInput::IsKeyDown(SDL_Scancode key) {

    return !key_state[key];
}

bool HandleInput::IsFingerDown() {

    return touch_down;
}

bool HandleInput::IsFingerUp() {

    return touch_up;
}

bool HandleInput::IsFigerMotion()  {

    return touch_motion;
}

bool HandleInput::IsMouseLeftButton() {

    return button_left;
}

bool HandleInput::IsMouseRightButton() {

    return button_right;
}

bool HandleInput::IsMouseMiddleButton() {

    return button_middle;
}

bool HandleInput::IsWindowQuit() {

    return window_quit;
}

Vector2i HandleInput::GetMousePosition() {

    return mouse_position;
}

Vector2f HandleInput::GetTouchPosition() {

    return touch_position;
}
