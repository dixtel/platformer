#ifndef PLAYER_H
#define PLAYER_H

#include <SDL2/SDL.h>

#include "include/rectangle.h"
#include "include/rectanglecollision.h"
#include "include/gameobject.h"

#include "include/vectro2.h"

enum PLAYER_INPUT_TYPE {
    MOVE_RIGHT,
    MOVE_LEFT,
    JUMP,
    NONE
};

class Player : public GameObject
{
public:

    Player();

    void Init(Vector2f position, Vector2u size, SDL_Texture *texture);

    void UpdatePhysics(float dt);
    void Update();
    void HandleInput(PLAYER_INPUT_TYPE input);

    void OnGround();

    Rectangle *GetRectangle();
    RectangleCollision *GetRectangleCollision();

private:

    SDL_Texture *texture = nullptr;
    SDL_Rect destination_texture;

    Rectangle rectangle;
    RectangleCollision rectangle_collision;

    Vector2f position;
    Vector2u size;

    Vector2f velocity;
    float acceleration;
    float speed;
    float jump_force;
    float max_speed;
    float max_jump;
    float gravity;
    float friction;

    bool is_jump;
    bool is_fall;
    bool is_on_ground;

    bool jump;
    bool move_right;
    bool move_left;
};

#endif // PLAYER_H
