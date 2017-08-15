#include "include/player.h"

Player::Player() {

    is_jump = false;
    is_fall = false;
    jump = false;
    move_right = false;
    move_left = false;
}

void Player::Init(Vector2f position, Vector2u size, SDL_Texture *texture) {

    this->position = position;
    this->size = size;
    this->texture = texture;

    destination_texture = {0, 0, size.x, size.y};

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetTexture(texture);
    rectangle.SetDestinationTexture(destination_texture);

    rectangle_collision.SetPosition(position);
    rectangle_collision.SetSize(size);

    Update();
}

void Player::UpdatePhysics(float dt) {

    if (move_right) {

        velocity += {speed * acceleration * dt, speed * acceleration * dt};
    }

    if (move_left) {

        velocity -= {speed * acceleration * dt, speed * acceleration * dt};
    }

    if (jump && (is_jump == false) && (is_fall == false) && (is_on_ground == true)) {

        is_jump = true;
        is_on_ground = false;

        velocity.y += jump_force;
    }

    velocity.y -= gravity * dt;

    if (is_jump) {

        // TODO animation handle
    }

    if (is_fall) {

        // TODO animation handle
    }

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

    position += velocity;

}

void Player::Update() {

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetDestinationTexture(destination_texture);

    rectangle_collision.SetPosition(position);
    rectangle_collision.SetSize(size);
}

void Player::HandleInput(PLAYER_INPUT_TYPE input) {

    if (input == MOVE_RIGHT) {

        move_right = true;
    }

    if (input == MOVE_LEFT) {

        move_left = true;
    }

    if (input == JUMP) {

        jump = true;
    }

    if (input == NONE) {

        move_right = false;
        move_left = false;
        jump = false;
    }
}

void Player::OnGround() {

    is_jump = true;
    is_fall = false;
    is_on_ground = true;

    velocity.y = 0;
}

Rectangle *Player::GetRectangle() {

    return &rectangle;
}

RectangleCollision *Player::GetRectangleCollision() {

    return &rectangle_collision;
}
