#ifndef DECORATION_H
#define DECORATION_H

#include <SDL2/SDL.h>

#include "include/gameobject.h"
#include "include/math/vector2.h"

class Decoration : public GameObject
{
public:

    Decoration();

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

#endif // DECORATION_H
