#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "include/rectangle.h"
#include "include/rectanglecollision.h"
#include "include/vectro2.h"

namespace GameObjectInput {
enum Type {
    RIGHT = 1,
    LEFT = 2,
    DOWN = 3,
    UP = 4,
    CLICK_ON_OBJECT = 5,
    NONE = 6
};
}

class GameObject
{
public:

    virtual ~GameObject() {}

    virtual void Init(Vector2f position, Vector2u size, SDL_Texture *texture) = 0;
    virtual void UpdatePhysics(float dt) = 0;
    virtual void Update() = 0;
    virtual void HandleInput(GameObjectInput::Type input) = 0;
    virtual void OnGround() {}

    virtual Rectangle *GetRectangle() = 0;
    virtual RectangleCollision *GetRectangleCollision() = 0;
};


#endif // GAMEOBJECT_H
