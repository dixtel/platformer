#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "include/rectangle.h"
#include "include/rectanglecollision.h"
#include "include/gameobject.h"
#include "include/math/vector2.h"
#include "include/imageloader.h"

class Player : public GameObject
{
public:

    Player();

    void Init(Vector2f position, Vector2u size, SDL_Texture *texture, ImageLoader *image_loader);

    void UpdatePhysics(double dt);
    void Update();
    void HandleInput(GameObjectInput input);
    void Bring(GameObject *game_object);
    bool IsBringGameObject();
    bool IsBringState();

    void SetPosition(Vector2f position);

    Rectangle *GetRectangle();
    RectangleCollision *GetRectangleCollision();
    GameObject *GetBringerGameObject();
    Vector2f GetPosition();
    Vector2u GetSize();
private:

    Rectangle          rectangle;
    RectangleCollision rectangle_collision;

    Vector2f           position;
    Vector2u           size;

    // bringer object variables
    Vector2f           bringer_object_position;
    SDL_Rect           bring_area;
    GameObject        *bringer_object = nullptr;

    // physics
    Vector2f           velocity;
    float              acceleration;
    float              speed;
    float              jump_force;
    float              max_speed;
    float              gravity;
    float              friction;

    // states, events
    bool               is_jump_state;
    bool               is_player_right_state;
    bool               is_player_left_state;
    bool               is_bring_game_object_state;

    bool               bring_object_event[2];
    bool               jump_event;
    bool               move_right_event;
    bool               move_left_event;
    bool               move_down_event;
    bool               move_up_event;
};

#endif // PLAYER_H
