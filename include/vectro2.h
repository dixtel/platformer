#ifndef VECTRO2_H
#define VECTRO2_H

struct Vector2f {

    float x;
    float y;

    Vector2f() {}

    Vector2f(float x, float y) {

        this->x = x;
        this->y = y;
    }

    Vector2f operator+=(Vector2f vec) {

       return {x - vec.x, y - vec.y};
    }

    Vector2f operator-=(Vector2f vec) {

       return {x - vec.x, y - vec.y};
    }

    Vector2f operator+(Vector2f vec) {

        return Vector2f {x + vec.x, y + vec.y};
    }

    Vector2f operator-(Vector2f vec) {

        return Vector2f {x - vec.x, y - vec.y};
    }

    Vector2f operator*(float num) {

        return Vector2f {x * num, y * num};
    }
};

struct Vector2i {

    int x;
    int y;

    Vector2i() {}

    Vector2i(int x, int y) {

        this->x = x;
        this->y = y;
    }

    Vector2i operator+=(Vector2i vec) {

       return {x - vec.x, y - vec.y};
    }

    Vector2i operator-=(Vector2i vec) {

       return {x - vec.x, y - vec.y};
    }

    Vector2i operator+(Vector2i vec) {

        return Vector2i {x + vec.x, y + vec.y};
    }

    Vector2i operator-(Vector2i vec) {

        return Vector2i {x - vec.x, y - vec.y};
    }

    Vector2i operator*(float num) {

        return Vector2i {x * num, y * num};
    }
};

struct Vector2u {

    unsigned x;
    unsigned y;

    Vector2u() {}

    Vector2u(unsigned x, unsigned y) {

        this->x = x;
        this->y = y;
    }

    Vector2u operator+=(Vector2u vec) {

       return {x - vec.x, y - vec.y};
    }

    Vector2u operator-=(Vector2u vec) {

       return {x - vec.x, y - vec.y};
    }

    Vector2u operator+(Vector2u vec) {

        return Vector2u {x + vec.x, y + vec.y};
    }

    Vector2u operator-(Vector2u vec) {

        return Vector2u {x - vec.x, y - vec.y};
    }

    Vector2u operator*(float num) {

        return Vector2u {x * num, y * num};
    }

};

#endif // VECTRO2_H
