#include "include/gameobjects/player.h"

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

    destination_texture = {0, 0, size.x, size.y};

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetTexture(texture);
    rectangle.SetSourceTexture(destination_texture);

    rectangle_collision.Init(position, size, CollisionType::RIGHTBODY);

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
    rectangle_collision.SetPosition(position);
}

void Player::Update() {

    position = rectangle_collision.GetPosition();

    rectangle.SetPosition(position);
    rectangle.SetSize(size);
    rectangle.SetSourceTexture(destination_texture);
}

void Player::HandleInput(GameObjectInput::Type input) {

    if (input == GameObjectInput::NONE) {

        move_right = false;
        move_left = false;
        jump = false;

        return;
    }

    if (input == GameObjectInput::RIGHT) {

        move_right = true;
    }

    if (input == GameObjectInput:: LEFT) {

        move_left = true;
    }

    if (input == GameObjectInput::UP) {

        jump = true;
    }

    if (input == GameObjectInput::CLICK_ON_OBJECT) {

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
