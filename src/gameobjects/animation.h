#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL2/SDL.h>

#include "include/rectangle.h"
#include "include/math/vector2.h"
#include "include/imageloader.h"

#include <vector>
#include <map>

class Animation
{
public:
    Animation();
    ~Animation();

    void Init(ImageLoader *image_loader);
    void Update(float dt);
    bool LoadAnimation(std::string path, int frame_width, int frame_height, int space_x, int space_y);
    void SetAnimationRow(int row);
    void SetFrameSpeed(float frame_speed);
    void SetAnimationPosition(Vector2f position);
    void StartAnimation();
    void EnableRepeat();
    void DisableRepeat();

    Rectangle *GetCurrentFrame();

private:

    void AddFrmae(int row, SDL_Texture *frame);
    void UpdateCurrentFrame();

    Rectangle *current_animation_rectangle = nullptr;
    SDL_Texture *texture_animation;
    std::map<int, std::vector<Rectangle*>> frames;
    ImageLoader *image_loader = nullptr;

    int frame_width;
    int frame_height;
    int width;
    int height;
    int rows;
    int size_od_row_elements;
    int space_x;
    int space_y;

    int current_row_animation;
    int current_frame;
    float frame_speed;
    float current_time;
    Vector2f animation_position;

    bool repeat;
    bool animation_start;
    bool is_animation;
};

#endif // ANIMATION_H
