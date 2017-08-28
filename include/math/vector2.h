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

    bool operator!=(const Vector2f &vec) {

        if ((x == vec.x) && (y == vec.y))
            return false;
        return true;
    }

    Vector2f &operator+=(const Vector2f &vec) {

        x += vec.x;
        y += vec.y;
        return *this;
    }

    Vector2f &operator-=(const Vector2f &vec) {

        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    Vector2f operator+(const Vector2f &vec2) {

        Vector2f vec(x + vec2.x, y + vec2.y);
        return vec;
    }

    Vector2f operator-(const Vector2f &vec2) {

        Vector2f vec(x - vec2.x, y - vec2.y);
        return vec;
    }

    Vector2f operator*(const Vector2f &vec2) {

        Vector2f vec(x * vec2.x, y * vec2.y);
        return vec;
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

    bool operator!=(const Vector2i &vec) {

        if ((x == vec.x) && (y == vec.y))
            return true;
        return false;
    }

    Vector2i &operator+=(const Vector2i &vec) {

        x += vec.x;
        y += vec.y;
        return *this;
    }

    Vector2i &operator-=(const Vector2i &vec) {

        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    Vector2i operator+(const Vector2i &vec2) {

        Vector2i vec(x + vec2.x, y + vec2.y);
        return vec;
    }

    Vector2i operator-(const Vector2i &vec2) {

        Vector2i vec(x - vec2.x, y - vec2.y);
        return vec;
    }

    Vector2i operator*(const Vector2i &vec2) {

        Vector2i vec(x * vec2.x, y * vec2.y);
        return vec;
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

    bool operator!=(const Vector2u &vec) {

        if ((x == vec.x) && (y == vec.y))
            return true;
        return false;
    }

    Vector2u &operator+=(const Vector2u &vec) {

        x += vec.x;
        y += vec.y;
        return *this;
    }

    Vector2u &operator-=(const Vector2u &vec) {

        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    Vector2u operator+(const Vector2u &vec2) {

        Vector2u vec(x + vec2.x, y + vec2.y);
        return vec;
    }

    Vector2u operator-(const Vector2u &vec2) {

        Vector2u vec(x - vec2.x, y - vec2.y);
        return vec;
    }

    Vector2u operator*(const Vector2u &vec2) {

        Vector2u vec(x * vec2.x, y * vec2.y);
        return vec;
    }
};

#endif // VECTRO2_H
