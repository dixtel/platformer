#include "include/animation.h"

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
    start_animation      = false;
    break_animation      = false;
    is_animation         = false;
}

Animation::~Animation() {

    for (std::map<int, std::vector<Rectangle*>>::iterator it_map = frames.begin(); it_map != frames.end(); ++it_map) {

        for (std::vector<Rectangle*>::iterator it_vector = it_map->second.begin(); it_vector != it_map->second.end(); ++it_vector) {

            if (*it_vector != nullptr)
                delete *it_vector;
        }
    }

    image_loader = nullptr;
    SDL_FreeSurface(surface_animation);
}

void Animation::Init(ImageLoader *image_loader) {

    this->image_loader = image_loader;
}

void Animation::Update(float dt) {

    if (break_animation) {

        current_time = 0;
        current_frame = 0;

        is_animation = false;
        break_animation = false;
    }

    if (start_animation) {

        current_time = dt;
        current_frame = 0;

        start_animation = false;
        is_animation = true;
    }

    if (is_animation) {

        if (current_time >= frame_speed) {

            ++current_frame;
            current_time = 0;
        }

        if (current_frame >= size_od_row_elements) {

            current_frame = 0;

            if (!repeat)
                is_animation = false;
        }

        current_time += dt;
    }

    SDL_Log("current row %i current frame %i", current_row_animation, current_frame);
}

bool Animation::LoadAnimation(std::string path, int frame_width, int frame_height, int space_x, int space_y) {

    this->frame_width  = frame_width;
    this->frame_height = frame_height;
    this->space_x      = space_x;
    this->space_y      = space_y;

    surface_animation = image_loader->LoadSurface(path.c_str());

    if (!surface_animation)
        return false;

    width = surface_animation->w;
    height = surface_animation->h;

    float amounts_of_rows = height / (frame_height + 2 * space_y);
    float amounts_of_row_elements = width / (frame_width + 2 * space_x);

    if ((amounts_of_rows != int(amounts_of_rows)) || (amounts_of_row_elements != int(amounts_of_row_elements)))
        return false;

    rows = amounts_of_rows;
    size_od_row_elements = amounts_of_row_elements;

    CreateRows(rows);

    int current_y_position = space_y;

    for (int y = 0; y < rows; ++y) {

        int current_x_position = space_x;

        for (int x = 0; x < size_od_row_elements; ++x) {

            SDL_Surface *current_surface_frame = SDL_CreateRGBSurface(NULL, frame_width, frame_height, 32, 0, 0, 0, 0);
            SDL_Log("%i %i %i %i", current_x_position, current_y_position, frame_width, frame_height);
            SDL_Rect src_rect = {current_x_position, current_y_position, frame_width, frame_height};
            SDL_BlitSurface(surface_animation, &src_rect, current_surface_frame, nullptr);

            AddFrmae(y, image_loader->ConvertSurfaceToTexture(current_surface_frame));

            SDL_FreeSurface(current_surface_frame);

            current_x_position += frame_width + (2 * space_x);
        }

        current_y_position += frame_height + (2 * space_y);
    }

    return true;
}

void Animation::SetAnimationRow(int row) {

    if (row > -1 && row < frames.size())
        current_row_animation = row;
}

void Animation::SetFrameSpeed(float frame_speed) {

    if (frame_speed > 0)
        this->frame_speed = frame_speed;
}

void Animation::SetAnimationPosition(Vector2f position) {

    animation_position = position;
}

Rectangle *Animation::GetCurrentFrameRectangle() {

    Rectangle *frame = frames[current_row_animation][current_frame];
    frame->SetPosition(animation_position);

    return frame;
}

void Animation::StartAnimation() {

    start_animation = true;
}

void Animation::BreakAnimation() {

    break_animation = true;
}

void Animation::EnableRepeat() {

    repeat = true;
}

void Animation::DisableRepeat() {

    repeat = false;
}

void Animation::CreateRows(int rows) {

    std::vector<Rectangle*> vector;

    for (int i = 0; i < rows; ++i)
        frames.insert(std::pair<int, std::vector<Rectangle*>>(i, vector));
}

void Animation::AddFrmae(int row, SDL_Texture *frame) {

    Rectangle *frm = new Rectangle();
    frm->SetSize(Vector2u(frame_width, frame_height));
    frm->SetTexture(frame);

    if (frames.find(row) != frames.end())
        frames.find(row)->second.push_back(frm);
}
