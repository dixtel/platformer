#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL.h>

#include "include/rectangle.h"
#include "include/rectanglecollision.h"
#include "include/imageloader.h"
#include "include/animation.h"
#include "include/math/vector2.h"


#include <string>

enum GameObjectInput {
    RIGHT_ON,
    RIGHT_OFF,
    LEFT_ON,
    LEFT_OFF,
    DOWN_ON,
    DOWN_OFF,
    UP_ON,
    UP_OFF,
    SPACEBAR_ON,
    SPACEBAR_OFF
};

class GameObject
{
public:

    virtual ~GameObject() {}

    virtual void Init(Vector2f position, Vector2u size, SDL_Texture *texture, ImageLoader *image_loader) = 0;
    virtual void UpdatePhysics(double dt) = 0;
    virtual void Update() = 0;
    virtual void HandleInput(GameObjectInput input) = 0;
    virtual void OnGround() {}
    virtual void Bring(GameObject *game_object) {}
    virtual void DisablePhysics() {}
    virtual void EnablePhysics() {}
    virtual bool IsBringState() {return false;}
    virtual bool IsBringGameObject() {}

    void SetLayerType(std::string layer_type) {this->layer_type = layer_type;}
    virtual void SetPosition(Vector2f position) = 0;
    virtual void SetVelocity(Vector2f velocity) {}

    virtual GameObject *GetBringerGameObject() {}
    virtual Rectangle *GetRectangle() = 0;
    virtual RectangleCollision *GetRectangleCollision() = 0;
    std::string GetLayerType() {return layer_type;}
    virtual Vector2f GetPosition() = 0;
    virtual Vector2u GetSize() = 0;

private:

    std::string layer_type;
};


#endif // GAMEOBJECT_H
