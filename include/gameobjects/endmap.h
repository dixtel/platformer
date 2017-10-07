#ifndef ENDMAP_H
#define ENDMAP_H

#include <SDL2/SDL.h>

#include "include/gameobject.h"
#include "include/math/vector2.h"

class EndMap : public GameObject
{
public:

    EndMap();

    void Init(Vector2f position, Vector2u size, SDL_Texture *texture, ImageLoader *image_loader);

    void UpdatePhysics(double dt);
    void Update();
    void HandleInput(GameObjectInput input);

    void SetPosition(Vector2f position);

    Rectangle *GetRectangle();
    RectangleCollision *GetRectangleCollision();
    Vector2f GetPosition();
    Vector2u GetSize();
private:

    Rectangle          rectangle;
    RectangleCollision rectangle_collision;

    Vector2f           position;
    Vector2u           size;
};

#endif // ENDMAP_H
