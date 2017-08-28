#ifndef GROUND_H
#define GROUND_H

#include <SDL2/SDL.h>

#include "include/rectangle.h"
#include "include/rectanglecollision.h"
#include "include/gameobject.h"
#include "include/math/vector2.h"

class Ground : public GameObject
{
public:

    Ground();

    void Init(Vector2f position, Vector2u size, SDL_Texture *texture);

    void UpdatePhysics(double dt);
    void Update();
    void HandleInput(GameObjectInput input);

    Rectangle *GetRectangle();
    RectangleCollision *GetRectangleCollision();
private:

    SDL_Rect           destination_texture;
    Rectangle          rectangle;
    RectangleCollision rectangle_collision;

    Vector2f           position;
    Vector2u           size;
};

#endif // GROUND_H
