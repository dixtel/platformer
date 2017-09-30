#ifndef BOX1_H
#define BOX1_H

#include <SDL2/SDL.h>

#include "include/rectangle.h"
#include "include/rectanglecollision.h"
#include "include/gameobject.h"
#include "include/math/vector2.h"

class Box1 : public GameObject
{
public:

    Box1();

    void Init(Vector2f position, Vector2u size, SDL_Texture *texture, ImageLoader *image_loader);

    void UpdatePhysics(double dt);
    void Update();
    void HandleInput(GameObjectInput input);
    void DisablePhysics();
    void EnablePhysics();

    void SetPosition(Vector2f position);
    void SetVelocity(Vector2f velocity);

    Rectangle *GetRectangle();
    RectangleCollision *GetRectangleCollision();
    Vector2f GetPosition();
    Vector2u GetSize();

private:
    Rectangle          rectangle;
    RectangleCollision rectangle_collision;

    Vector2f           position;
    Vector2u           size;

    Vector2f           velocity;
    float              friction;
    float              gravity;
    bool               physics_mode;
};

#endif // BOX1_H
