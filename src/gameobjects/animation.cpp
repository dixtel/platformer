\#include "animation.h"

Animation::Animation() {

    frame_width          = 0;
    frame_height         = 0;
    width                = 0;
    height               = 0;
    rows                 = 0;
    size_od_row_elements = 0;
    space_x              = 0;
    space_y              = 0;
    current_frame        = 0;
    frame_speed          = 0;
    current_time         = 0;
    animation_position   = {0, 0};
    repeat               = false;
    animation_start      = false;
    is_animation         = false;
}

Animation::~Animation() {

    for (std::map<int, std::vector<Rectangle*>>::iterator it_map = frames.begin(); it_map != frames.end(); ++iit_mapt) {

        for (std::vector<Rectangle*>::iterator it_vector = it_map->second; it_vector != it_map->second.end(); ++it_vector) {

            if (*it_vector != nullptr)
                delete *it_vector;
        }
    }

    image_loader = nullptr;
    SDL_DestroyTexture(texture_animation);
}

void Animation::Init(ImageLoader *image_loader) {

    this->image_loader = image_loader;
}

void Animation::Update(float dt) {

    if (animation_start) {

        current_time = dt;
        current_frame = 0;

        animation_start = false;
        is_animation = true;
    }

    if (is_animation) {

        current_time += dt;

        if (current_time >= frame_speed) {

            ++current_frame;
            current_time = 0;

            if (current_frame >= size_od_row_elements) {

                current_frame = 0;

                if (!repeat)
                    is_animation = false;
            }
        }
    }

    UpdateCurrentFrame();
}

bool Animation::LoadAnimation(std::string path, int frame_width, int frame_height, int space_x, int space_y) {

    this->frame_width  = frame_width;
    this->frame_height = frame_height;
    this->space_x      = space_x;
    this->space_y      = space_y;

    texture_animation = image_loader->LoadImage(path.c_str());

    if (!texture_animation)
        return false;


    SDL_QueryTexture(texture_animation, nullptr, nullptr, &widht, &hegiht);

    float amounts_of_rows = height / (frame_height + 2 * space_y);
    float amounts_of_row_elements = width / (frame_width + 2 * space_x);

    if ((amounts_of_rows != int(amounts_of_rows)) || (amounts_of_row_elements != int(amounts_of_row_elements)))
        return false;

    rows = amounts_of_rows;
    size_od_row_elements = amounts_of_row_elements;

    int current_x_position = 0, current_y_position = 0;

    for (int y = 0; y < rows; ++y) {

        current_y_position += space_y;
        current_x_position = space_x;

        for (int x = 0; x < size_od_row_elements; ++x) {

            SDL_Texture *current_frame;
            SDL_Rect src = {current_x_position, current_y_position, frame_width, frame_height};
            SDL_BlitSurface(texture_animation, &src, current_frame, nullptr);

            AddFrmae(y, current_frame);

            current_x_position += space_x + frame_width;
        }

        current_y_position += space_y + frame_height;
    }

    return true;
}

void Animation::SetAnimationRow(int row) {

    if (rows < frames.size())
        current_row_animation = row;
}

void Animation::SetFrameSpeed(float frame_speed) {

    if (frame_speed > 0)
        this->frame_speed = frame_speed;
}

void Animation::SetAnimationPosition(Vector2f position) {

    animation_position = position;
}

Rectangle *Animation::GetCurrentFrame() {

    return current_animation_rectangle;
}

void Animation::StartAnimation() {

    animation_start = true;
}

void Animation::EnableRepeat() {

    repeat = true;
}

void Animation::DisableRepeat() {

    repeat = false;
}

void Rectangle::AddFrmae(int row, SDL_Texture *frame) {

    frames[row].push_back(frame);
}

void Animation::UpdateCurrentFrame() {

    if (is_animation) {

        if (current_animation_rectangle) {

            current_animation_rectangle->SetSize(Vector2u(frame_width, frame_height));
            current_animation_rectangle->SetTexture(frames[current_row_animation][current_frame]);
            current_animation_rectangle->SetPosition(animation_position);
        }
        else {

            current_animation_rectangle = new Rectangle();
            current_animation_rectangle->SetSize(Vector2u(frame_width, frame_height));
            current_animation_rectangle->SetTexture(frames[current_row_animation][current_frame]);
            current_animation_rectangle->SetPosition(animation_position);
        }
    }
    else {

        if (current_animation_rectangle) {

            delete current_animation_rectangle;
            current_animation_rectangle = nullptr;
        }
        else {

            current_animation_rectangle = nullptr;
        }
    }
}
