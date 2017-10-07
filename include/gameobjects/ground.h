#ifndef GROUND_H
#define GROUND_H

#include <SDL2/SDL.h>

#include "include/gameobject.h"
#include "include/math/vector2.h"

class Ground : public GameObject
{
public:

    Ground();

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

    SDL_Rect           destination_texture;
    Rectangle          rectangle;
    RectangleCollision rectangle_collision;

    Vector2f           position;
    Vector2u           size;
};

#endif // GROUND_H
