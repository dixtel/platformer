#ifndef ANGLE_H
#define ANGLE_H

#include "include/vectro2.h"

#include <cmath>
#include <iostream>


#define PI  3.14159265

struct Angle {

    float degree;

    Angle() {degree = 0;}

    void FixAngle() {

        if (degree > 360.0)
            degree = std::fmod(degree, 360);

        else if (degree < 0.0){
            while (degree < 0) {
                degree += 360;
            }
        }
    }

    Angle(float deegre) {

        this->degree = deegre;
        FixAngle();
    }

    void operator=(const float &deegre) {

        this->degree = deegre;
        FixAngle();
    }

    Angle &operator+=(const float &deegre) {

        this->degree += deegre;
        FixAngle();

        return *this;
    }

    Angle &operator-=(const float &deegre) {

        this->degree -= deegre;

        FixAngle();

        return *this;
    }
};

static Angle GetAngle(Vector2f A, Vector2f B) {

    Vector2f dir = {B.x - A.x, A.y - B.y};

    Angle angle(atan2(dir.y, dir.x) * 180 / PI);

    return angle;
}

#endif // ANGLE_H
