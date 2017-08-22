#include "include/collision.h"

Collision::Collision() {

}

bool Collision::IsCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> &coliders) {

    Vector2f points[4] = {main_object->GetCurrentPoint('A'), main_object->GetCurrentPoint('B'),
                          main_object->GetCurrentPoint('C'), main_object->GetCurrentPoint('D')};

    for (int i = 0; i < coliders.size(); ++i) {

        Vector2f colider_corners[2] = {coliders[i]->GetCurrentPoint('A'), coliders[i]->GetCurrentPoint('C')};

        for (int j = 0; j < 4; ++j) {

            if ((points[j].x > colider_corners[0].x) && (points[j].x < colider_corners[1].x)
                && (points[j].y > colider_corners[0].y) && (points[j].y < colider_corners[1].y))
                return true;
        }
    }

    return false;
}

void Collision::SetCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> &coliders) {

    Vector2f *current_points[4] = {&main_object->GetCurrentPoint('A'), &main_object->GetCurrentPoint('B'),
                                  &main_object->GetCurrentPoint('C'), &main_object->GetCurrentPoint('D')};
    Vector2f *old_points[4] = {&main_object->GetOldPoint('A'), &main_object->GetOldPoint('B'),
                              &main_object->GetOldPoint('C'), &main_object->GetOldPoint('D')};


    for (int i = 0; i < coliders.size(); ++i) {

        Vector2f colider_current_points[4] = {coliders[i]->GetCurrentPoint('A'), coliders[i]->GetCurrentPoint('B'),
                                              coliders[i]->GetCurrentPoint('C'), coliders[i]->GetCurrentPoint('D')};
        Vector2f colider_old_points[4] = {coliders[i]->GetOldPoint('A'), coliders[i]->GetOldPoint('B'),
                                          coliders[i]->GetOldPoint('C'), coliders[i]->GetOldPoint('D')};
        // main object point A
        Vector2f intersect_position;
        if ((intersect_position = GetIntersect(old_points[0], current_points[0], colider_current_points[1], colider_current_points[2])) != Vector2f {0, 0}) {

            SDL_Log("collision A");

            main_object->EnableCollisionXAxsis();
            FixPosition(intersect_position, intersect_position, main_object, old_points[0], current_points[0], colider_current_points[1], colider_current_points[2]);

            return;
        }

        else if ((intersect_position = GetIntersect(old_points[0], current_points[0], colider_current_points[2], colider_current_points[3])) != Vector2f {0, 0}) {

            SDL_Log("collision A");

            main_object->EnableCollisionYAxsis();
            FixPosition(intersect_position, intersect_position, main_object, old_points[0], current_points[0], colider_current_points[2], colider_current_points[3]);

            return;
        }

        // main object point B
        if ((intersect_position = GetIntersect(old_points[1], current_points[1], colider_current_points[0], colider_current_points[3])) != Vector2f {0, 0}) {

            SDL_Log("collision B");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {-float(main_object->GetSize().x), 0};

            main_object->EnableCollisionXAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[1], current_points[1], colider_current_points[0], colider_current_points[3]);

            return;
        }

        else if ((intersect_position = GetIntersect(old_points[1], current_points[1], colider_current_points[3], colider_current_points[2])) != Vector2f {0, 0}) {

            SDL_Log("collision B");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {-float(main_object->GetSize().x), 0};

            main_object->EnableCollisionYAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[1], current_points[1], colider_current_points[3], colider_current_points[2]);

            return;
        }

        // main object point C
        if ((intersect_position = GetIntersect(old_points[2], current_points[2], colider_current_points[0], colider_current_points[1])) != Vector2f {0, 0}) {

            SDL_Log("collision C");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {-float(main_object->GetSize().x), -float(main_object->GetSize().y)};

            main_object->EnableCollisionYAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[2], current_points[2], colider_current_points[0], colider_current_points[1]);

            return;
        }

        else if ((intersect_position = GetIntersect(old_points[2], current_points[2], colider_current_points[0], colider_current_points[3])) != Vector2f {0, 0}) {

            SDL_Log("collision C");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {-float(main_object->GetSize().x), -float(main_object->GetSize().y)};

            main_object->EnableCollisionXAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[2], current_points[2], colider_current_points[0], colider_current_points[3]);

            return;
        }

        // main object point D
        if ((intersect_position = GetIntersect(old_points[3], current_points[3], colider_current_points[0], colider_current_points[1])) != Vector2f {0, 0}) {

            SDL_Log("collision D");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {0, -float(main_object->GetSize().y)};

            main_object->EnableCollisionYAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[3], current_points[3], colider_current_points[0], colider_current_points[1]);

            return;
        }

        else if ((intersect_position = GetIntersect(old_points[3], current_points[3], colider_current_points[1], colider_current_points[2])) != Vector2f {0, 0}) {

            SDL_Log("collision D");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {0, -float(main_object->GetSize().y)};

            main_object->EnableCollisionXAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[3], current_points[3], colider_current_points[1], colider_current_points[2]);

            return;
        }
    }

    for (int i = 0; i < coliders.size(); ++i) {

        Vector2f colider_current_points[4] = {coliders[i]->GetCurrentPoint('A'), coliders[i]->GetCurrentPoint('B'),
                                              coliders[i]->GetCurrentPoint('C'), coliders[i]->GetCurrentPoint('D')};
        Vector2f colider_old_points[4] = {coliders[i]->GetOldPoint('A'), coliders[i]->GetOldPoint('B'),
                                          coliders[i]->GetOldPoint('C'), coliders[i]->GetOldPoint('D')};
        Vector2f intersect_position;


        // main object point D
        if ((intersect_position = GetIntersect(old_points[3], current_points[3], colider_current_points[0], colider_current_points[1])) != Vector2f {0, 0}) {

            SDL_Log("collision D");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {0, -float(main_object->GetSize().y)};

            main_object->EnableCollisionYAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[3], current_points[3], colider_current_points[0], colider_current_points[1]);

            return;
        }

        else if ((intersect_position = GetIntersect(old_points[3], current_points[3], colider_current_points[1], colider_current_points[2])) != Vector2f {0, 0}) {

            SDL_Log("collision D");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {0, -float(main_object->GetSize().y)};

            main_object->EnableCollisionXAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[3], current_points[3], colider_current_points[1], colider_current_points[2]);

            return;
        }
        // main object point C
        if ((intersect_position = GetIntersect(old_points[2], current_points[2], colider_current_points[0], colider_current_points[1])) != Vector2f {0, 0}) {

            SDL_Log("collision C");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {-float(main_object->GetSize().x), -float(main_object->GetSize().y)};

            main_object->EnableCollisionYAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[2], current_points[2], colider_current_points[0], colider_current_points[1]);

            return;
        }

        else if ((intersect_position = GetIntersect(old_points[2], current_points[2], colider_current_points[0], colider_current_points[3])) != Vector2f {0, 0}) {

            SDL_Log("collision C");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {-float(main_object->GetSize().x), -float(main_object->GetSize().y)};

            main_object->EnableCollisionXAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[2], current_points[2], colider_current_points[0], colider_current_points[3]);

            return;
        }


        // main object point B
        if ((intersect_position = GetIntersect(old_points[1], current_points[1], colider_current_points[0], colider_current_points[3])) != Vector2f {0, 0}) {

            SDL_Log("collision B");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {-float(main_object->GetSize().x), 0};

            main_object->EnableCollisionXAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[1], current_points[1], colider_current_points[0], colider_current_points[3]);

            return;
        }

        else if ((intersect_position = GetIntersect(old_points[1], current_points[1], colider_current_points[3], colider_current_points[2])) != Vector2f {0, 0}) {

            SDL_Log("collision B");

            Vector2f fixed_intersect_position = intersect_position + Vector2f {-float(main_object->GetSize().x), 0};

            main_object->EnableCollisionYAxsis();
            FixPosition(intersect_position, fixed_intersect_position, main_object, old_points[1], current_points[1], colider_current_points[3], colider_current_points[2]);

            return;
        }
        // main object point A
        if ((intersect_position = GetIntersect(old_points[0], current_points[0], colider_current_points[1], colider_current_points[2])) != Vector2f {0, 0}) {

            SDL_Log("collision A");

            main_object->EnableCollisionXAxsis();
            FixPosition(intersect_position, intersect_position, main_object, old_points[0], current_points[0], colider_current_points[1], colider_current_points[2]);

            return;
        }

        else if ((intersect_position = GetIntersect(old_points[0], current_points[0], colider_current_points[2], colider_current_points[3])) != Vector2f {0, 0}) {

            SDL_Log("collision A");

            main_object->EnableCollisionYAxsis();
            FixPosition(intersect_position, intersect_position, main_object, old_points[0], current_points[0], colider_current_points[2], colider_current_points[3]);

            return;
        }
    }

    delete [] current_points;
    delete [] old_points;
}

void Collision::FixPosition(Vector2f intersect_position, Vector2f fixed_intersect_position, RectangleCollision *object, Vector2f object_old_position, Vector2f object_current_position, Vector2f colider_position_start, Vector2f colider_position_end) {

    float missing_distance = GetDistance(intersect_position, object_current_position);
    float fixed_distance = missing_distance * 0.6;
    std::string flip_type;

    Angle colider_angle = GetAngle(colider_position_start, colider_position_end);
    if ((colider_angle.degree == 90) || (colider_angle.degree == 270))
        flip_type = "vertical";
    else
        flip_type = "horizontal";

    Angle current_angle = GetAngle(object_old_position, object_current_position);
    Angle fixed_angle = GetFixedAngle(object_old_position, object_current_position, flip_type);

   // object->SetCollisionPosition(fixed_intersect_position);
    object->SetCurrentPosition(fixed_intersect_position);


    if (!((current_angle.degree == 0) || (current_angle.degree == 90) || (current_angle.degree == 180) || (current_angle.degree == 270)))
        MoveRectangleCollision(object, fixed_angle, fixed_distance);
}

void Collision::MoveRectangleCollision(RectangleCollision *object, Angle angle, float distance) {

    float x = cos(angle.degree * PI / 180);
    float y = -sin(angle.degree * PI / 180);

    Vector2f final_distance = {x * distance, y * distance};

    //object->SetCollisionPosition(object->GetPosition() + final_distance);
    object->SetCurrentPosition(object->GetPosition() + final_distance);
}

Angle Collision::GetFixedAngle(Vector2f start, Vector2f end, std::string flip_type) {

    Angle angle(GetAngle(start, end));

    if (flip_type == "horizontal") {

        if ((angle.degree > 270) || (angle.degree < 90)) angle.degree = 0;
        else if ((angle.degree > 90) && (angle.degree < 270)) angle.degree = 180;
    }
    else if (flip_type == "vertical") {

        if ((angle.degree > 0) && (angle.degree < 180)) angle.degree = 90;
        else if (angle.degree > 180) angle.degree = 270;
    }

    return angle;
}

