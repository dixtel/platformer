#include "include/gameobjects/player.h"

Player::Player() {

    bring_object_event[0]      = false;
    bring_object_event[1]      = false;
    is_jump_state              = false;
    is_player_right_state      = false;
    is_player_left_state       = false;
    is_bring_game_object_state = true;
    jump_event                 = false;
    move_right_event           = false;
    move_left_event            = false;
    move_down_event            = false;
    move_up_event              = false;
    velocity                   = {0, 0};
    acceleration               = 0;
    speed                      = 0;
    jump_force                 = 0;
    max_speed                  = 0;
    gravity                    = 0;
    friction                   = 0;
    position                   = {0, 0};
    size                       = {0, 0};
    bring_area                 = {0, 0, 5, 5};
}

void Player::Init(Vector2f position, Vector2u size, SDL_Texture *texture, ImageLoader *image_loader) {

    this->position = position;
    this->size = size;

    acceleration = 1;
    speed        = 17.5;
    jump_force   = 4;
    max_speed    = 5;
    gravity      = 8;
    friction     = 10;

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetTexture(texture);
    rectangle.SetSourceTexture({0, 0, size.x, size.y});

    rectangle_collision.Init(position, size, RIGHTBODY);

    Update();
}

void Player::UpdatePhysics(double dt) {

    if (move_right_event) {

        velocity.x += speed * acceleration * dt;
    }

    if (move_left_event) {

        velocity.x -= speed * acceleration * dt;
    }

    if (move_up_event) {

        jump_event = true;
    }
    else {

        jump_event = false;
    }

    if (jump_event && (is_jump_state == false)) {

        is_jump_state = true;

        velocity.y += -jump_force;
    }

    velocity.y += gravity * dt;

    if (velocity.x > 0) {

        velocity.x -= friction * dt;

        if (velocity.x < 0) {

            velocity.x = 0;
        }

        if (velocity.x > max_speed) {

            velocity.x = max_speed;
        }
    }
    else if (velocity.x < 0) {

        velocity.x += friction * dt;

        if (velocity.x > 0) {

            velocity.x = 0;
        }

        if (velocity.x < -max_speed) {

            velocity.x = -max_speed;
        }
    }

    velocity.x *= rectangle_collision.GetDecreasedXVelocityProcent();
    velocity.y *= rectangle_collision.GetDecreasedYVelocityProcent();

    if (rectangle_collision.GetCollisionXAxsis()) {

        velocity.x = 0;
    }

    if (rectangle_collision.GetCollisionYAxsis()) {

        velocity.y = 0;
    }

    if (rectangle_collision.GetCollisionYAxsisDown()) {

        is_jump_state = false;
    }


    position += velocity;
    rectangle_collision.SetPosition(position);

    if (is_player_right_state) {

        bring_area.x = position.x + size.x + 1;
        bring_area.y = position.y + ((size.y / 2) - (bring_area.h / 2));
        bringer_object_position = position + Vector2f(size.x + 1, -20);
    }
    else if (is_player_left_state) {

        bring_area.x = position.x - size.x - 1;
        bring_area.y = position.y + ((size.y / 2) - (bring_area.h / 2));
        bringer_object_position = position - Vector2f(size.x + 1, 20);
    }

    if (bringer_object) {

        bringer_object->SetPosition(bringer_object_position);

        if (bring_object_event[0] == false && bring_object_event[1] == true) {

            bringer_object->EnablePhysics();
            bringer_object->SetVelocity(velocity);
            bringer_object = nullptr;
            is_bring_game_object_state = false;
        }

    }
}

void Player::Update() {

    position = rectangle_collision.GetPosition();
    rectangle.SetPosition(position);
}

void Player::HandleInput(GameObjectInput input) {

    if (input == RIGHT_ON) {

        move_right_event = true;
        is_player_right_state = true;
        is_player_left_state = false;
    }

    else if (input == RIGHT_OFF) {

        move_right_event = false;
    }

    else if (input == LEFT_ON) {

        move_left_event = true;
        is_player_left_state = true;
        is_player_right_state = false;
    }

    else if (input == LEFT_OFF) {

        move_left_event = false;
    }

    else if (input == UP_ON) {

        move_up_event = true;
    }

    else if (input == UP_OFF) {

        move_up_event = false;
    }

    else if (input == DOWN_ON) {

        move_down_event = true;
    }

    else if (input == DOWN_OFF) {

        move_down_event = false;
    }

    else if (input == SPACEBAR_ON) {

        bring_object_event[0] = bring_object_event[1];
        bring_object_event[1] = true;
    }

    else if (input == SPACEBAR_OFF) {

        bring_object_event[0] = bring_object_event[1];
        bring_object_event[1] = false;
    }
}

void Player::Bring(GameObject *game_object) {

    SDL_Rect game_object_area = {game_object->GetPosition().x, game_object->GetPosition().y, game_object->GetSize().x, game_object->GetSize().y};
    SDL_Point bring_area_points[4] = {{bring_area.x, bring_area.y}, {bring_area.x + bring_area.w, bring_area.y},
                                     {bring_area.x + bring_area.w, bring_area.y + bring_area.h}, {bring_area.x, bring_area.y + bring_area.h}};

    for (int i = 0; i < 4; ++i) {

        if (SDL_PointInRect(&bring_area_points[i], &game_object_area) == SDL_TRUE) {
            SDL_Log("test");

            bringer_object = game_object;
            bringer_object->DisablePhysics();
            is_bring_game_object_state = true;
            return;
        }
    }
}


bool Player::IsBringGameObject() {

    return bringer_object;
}

bool Player::IsBringState() {

    if (bring_object_event[0] == false && bring_object_event[1] == true)
        return true;
    return false;
}

void Player::SetPosition(Vector2f position) {

    this->position = position;
}

Rectangle *Player::GetRectangle() {

    return &rectangle;
}

RectangleCollision *Player::GetRectangleCollision() {

    return &rectangle_collision;
}

GameObject *Player::GetBringerGameObject() {

    return bringer_object;
}

Vector2f Player::GetPosition() {

    return position;
}

Vector2u Player::GetSize() {

    return size;
}
