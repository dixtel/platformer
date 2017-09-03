#include "include/gameobjects/player.h"

Player::Player() {

    is_jump      = false;
    jump         = false;
    move_right   = false;
    move_left    = false;
    move_down    = false;
    move_up      = false;
    velocity     = {0, 0};
    acceleration = 0;
    speed        = 0;
    jump_force   = 0;
    max_speed    = 0;
    gravity      = 0;
    friction     = 0;
    position     = {0, 0};
    size         = {0, 0};
}

void Player::Init(Vector2f position, Vector2u size, SDL_Texture *texture) {

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

    if (move_right) {

        velocity.x += speed * acceleration * dt;
    }

    if (move_left) {

        velocity.x -= speed * acceleration * dt;
    }

    if (move_up) {

        jump = true;
    }
    else {

        jump = false;
    }

    if (jump && (is_jump == false)) {

        is_jump = true;

        velocity.y = -jump_force;
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

    if (rectangle_collision.GetCollisionXAxsis()) {

        velocity.x = 0;
    }

    if (rectangle_collision.GetCollisionYAxsis()) {

        velocity.y = 0;
    }

    if (rectangle_collision.GetCollisionYAxsisDown()) {

        is_jump = false;
    }

    position += velocity;
    rectangle_collision.SetPosition(position);
}

void Player::Update() {

    position = rectangle_collision.GetPosition();

    rectangle.SetPosition(position);
}

void Player::HandleInput(GameObjectInput input) {

    if (input == RIGHT_ON) {

        move_right = true;
    }

    if (input == RIGHT_OFF) {

        move_right = false;
    }

    if (input == LEFT_ON) {

        move_left = true;
    }

    if (input == LEFT_OFF) {

        move_left = false;
    }

    if (input == UP_ON) {

        move_up = true;
    }

    if (input == UP_OFF) {

        move_up = false;
    }

    if (input == DOWN_ON) {

        move_down = true;
    }

    if (input == DOWN_OFF) {

        move_down = false;
    }

    if (input == CLICK_ON_OBJECT_ON) {

    }

    if (input == CLICK_ON_OBJECT_OFF) {

    }
}

Rectangle *Player::GetRectangle() {

    return &rectangle;
}

RectangleCollision *Player::GetRectangleCollision() {

    return &rectangle_collision;
}
