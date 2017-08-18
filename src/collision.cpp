#include "include/collision.h"

Collision::Collision() {

}

bool Collision::IsCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> coliders) {

    SDL_Rect main_rect = main_object->GetCurrentRect();

    for (int i = 0; i < coliders.size(); ++i) {

        if (SDL_HasIntersection(&main_rect, &coliders[i]->GetCurrentRect()) == SDL_TRUE) {

            return true;
        }
    }

    return false;
}

void Collision::SetCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> coliders) {

    Vector2f current_points[4] = {main_object->GetCurrentPoint('A'), main_object->GetCurrentPoint('B'),
                                  main_object->GetCurrentPoint('C'), main_object->GetCurrentPoint('D')};
    Vector2f old_points[4] = {main_object->GetOldPoint('A'), main_object->GetOldPoint('B'),
                              main_object->GetOldPoint('C'), main_object->GetOldPoint('D')};

    for (int i = 0; i < coliders.size(); ++i) {

        Vector2f colider_current_points[4] = {coliders[i]->GetCurrentPoint('A'), coliders[i]->GetCurrentPoint('B'),
                                              coliders[i]->GetCurrentPoint('C'), coliders[i]->GetCurrentPoint('D')};
        Vector2f colider_old_points[4] = {coliders[i]->GetOldPoint('A'), coliders[i]->GetOldPoint('B'),
                                          coliders[i]->GetOldPoint('C'), coliders[i]->GetOldPoint('D')};
        // main object point A
        if (GetIntersect(old_points[0], current_points[0], colider_current_points[1], colider_current_points[2]) != Vector2f {0, 0}) {

            SDL_Log("collision A");

            return;
        }

        else if (GetIntersect(old_points[0], current_points[0], colider_current_points[2], colider_current_points[3]) != Vector2f {0, 0}) {

            SDL_Log("collision A");

            return;
        }

        // main object point B
        if (GetIntersect(old_points[1], current_points[1], colider_current_points[0], colider_current_points[3]) != Vector2f {0, 0}) {

            SDL_Log("collision B");

            return;
        }

        else if (GetIntersect(old_points[1], current_points[1], colider_current_points[3], colider_current_points[2]) != Vector2f {0, 0}) {

            SDL_Log("collision B");

            return;
        }

        // main object point C
        if (GetIntersect(old_points[2], current_points[0], colider_current_points[0], colider_current_points[1]) != Vector2f {0, 0}) {

            SDL_Log("collision C");

            return;
        }

        else if (GetIntersect(old_points[2], current_points[2], colider_current_points[0], colider_current_points[3]) != Vector2f {0, 0}) {

            SDL_Log("collision C");

            return;
        }

        // main object point D
        if (GetIntersect(old_points[3], current_points[3], colider_current_points[0], colider_current_points[1]) != Vector2f {0, 0}) {

            SDL_Log("collision D");

            return;
        }

        else if (GetIntersect(old_points[3], current_points[3], colider_current_points[1], colider_current_points[2]) != Vector2f {0, 0}) {

            SDL_Log("collision D");

            return;
        }

    }
}
