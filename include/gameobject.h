#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "include/rectangle.h"
#include "include/rectanglecollision.h"
#include "include/vectro2.h"

class GameObject
{
public:

    virtual ~GameObject() {}

    virtual void Init(Vector2f position, Vector2u size, SDL_Texture *texture) = 0;
    virtual void UpdatePhysics(float dt) = 0;
    virtual void Update() = 0;
    virtual void OnGround() = 0;

    virtual Rectangle *GetRectangle() = 0;
    virtual RectangleCollision *GetRectangleCollision() = 0;
};


#endif // GAMEOBJECT_H
