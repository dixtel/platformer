#include "include/collision.h"

Collision::Collision() {

}

bool Collision::IsCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> &coliders) {

    Vector2f points[4] = {main_object->GetPointPosition('A'), main_object->GetPointPosition('B'),
                          main_object->GetPointPosition('C'), main_object->GetPointPosition('D')};

    for (int i = 0; i < coliders.size(); ++i) {

        Vector2f colider_corners[2] = {coliders[i]->GetPointPosition('A'), coliders[i]->GetPointPosition('C')};

        for (int j = 0; j < 4; ++j) {

            if ((points[j].x >= colider_corners[0].x) && (points[j].x <= colider_corners[1].x)
                && (points[j].y >= colider_corners[0].y) && (points[j].y <= colider_corners[1].y))
                return true;
        }
    }

    return false;
}

void Collision::SetCollision(RectangleCollision *main_object, std::vector<RectangleCollision*> &coliders) {

    std::vector<RectangleCollision*> correct_coliders;

    Vector2f points[4] = {main_object->GetPointPosition('A'), main_object->GetPointPosition('B'),
                          main_object->GetPointPosition('C'), main_object->GetPointPosition('D')};

    for (int i = 0; i < coliders.size(); ++i) {

        Vector2f colider_corners[2] = {coliders[i]->GetPointPosition('A'), coliders[i]->GetPointPosition('C')};

        for (int j = 0; j < 4; ++j) {

            if ((points[j].x > colider_corners[0].x) && (points[j].x < colider_corners[1].x)
                && (points[j].y > colider_corners[0].y) && (points[j].y < colider_corners[1].y))
                correct_coliders.push_back(coliders[i]);
        }
    }

    for (int i = 0; i < correct_coliders.size(); ++i) {

        Vector2f colider_center = correct_coliders[i]->GetCenterPosition();
        Vector2f main_object_center = main_object->GetCenterPosition();

        std::vector<Vector> colider_vectors = ConvertToVectors(correct_coliders[i], colider_center);
        std::vector<Vector> main_object_vectors = ConvertToVectors(main_object, main_object_center);

        float objects_projection_axisx = GetProjection(colider_center, main_object_center, AXIS_X);
        float objects_projection_axisy = GetProjection(colider_center, main_object_center, AXIS_Y);

        float main_object_min_axisx = GetMinnimumProjection(main_object_vectors, AXIS_X);
        float main_object_max_axisx = GetMaxsimiumProjection(main_object_vectors, AXIS_X);
        float main_object_min_axisy = GetMinnimumProjection(main_object_vectors, AXIS_Y);
        float main_object_max_axisy = GetMaxsimiumProjection(main_object_vectors, AXIS_Y);

        float colider_min_axisx = GetMinnimumProjection(colider_vectors, AXIS_X);
        float colider_max_axisx = GetMaxsimiumProjection(colider_vectors, AXIS_X);
        float colider_min_axisy = GetMinnimumProjection(colider_vectors, AXIS_Y);
        float colider_max_axisy = GetMaxsimiumProjection(colider_vectors, AXIS_Y);

        // left axis side are negative, right positive
        bool main_object_left_axisx   = false;
        bool main_object_right_axisx  = false;
        bool main_object_left_axisy   = false;
        bool main_object_right_axisy  = false;

        // set main_objct side axis
        if (objects_projection_axisx < 0)
            main_object_left_axisx = true;
        else
            main_object_right_axisx = true;

        if (objects_projection_axisy < 0)
            main_object_left_axisy = true;
        else
            main_object_right_axisy = true;

        float gap_axisx = 0;
        float gap_axisy = 0;

        if (main_object_left_axisx)
            gap_axisx = fabs(objects_projection_axisx) - main_object_max_axisx + colider_min_axisx;
        else
            gap_axisx = objects_projection_axisx - colider_max_axisx + main_object_min_axisx;

        if (main_object_left_axisy)
            gap_axisy = fabs(objects_projection_axisy) - main_object_max_axisy + colider_min_axisy;
        else
            gap_axisy = objects_projection_axisy - colider_max_axisy + main_object_min_axisy;


        // collision occurs when all gap is negative
        if (gap_axisx < 0 && gap_axisy < 0) {

            float move_x = 0;
            float move_y = 0;

            // calculate move_x
            if (main_object_left_axisx && gap_axisx >= gap_axisy) {

                move_x = gap_axisx;
            }
            else if (main_object_right_axisx && gap_axisx >= gap_axisy) {

                move_x = -gap_axisx;
            }

            // calculate move_y
            if (main_object_left_axisy && gap_axisy >= gap_axisx) {

                move_y = gap_axisy;
            }
            else if (main_object_right_axisy && gap_axisy >= gap_axisx) {

                move_y = -gap_axisy;
            }

            // response to collision
            if (main_object->GetCollisionType() == CollisionType::RIGHTBODY && correct_coliders[i]->GetCollisionType() == CollisionType::RIGHTBODY) {

                main_object->Move(Vector2f(move_x / 2, move_y / 2));
                correct_coliders[i]->Move(Vector2f(-(move_x / 2), -(move_y / 2)));

                if (move_x != 0) {

                    main_object->EnableCollisionXAxsis();
                    correct_coliders[i]->EnableCollisionXAxsis();
                }

                if (move_y != 0) {

                    main_object->EnableCollisionYAxsis();
                    correct_coliders[i]->EnableCollisionYAxsis();
                }
            }
            else if (main_object->GetCollisionType() == CollisionType::RIGHTBODY && correct_coliders[i]->GetCollisionType() == CollisionType::STATICBODY) {

                main_object->Move(Vector2f(move_x, move_y));

                if (move_x != 0)
                    main_object->EnableCollisionXAxsis();

                if (move_y != 0)
                    main_object->EnableCollisionYAxsis();
            }
        }
    }
}

std::vector<Vector> Collision::ConvertToVectors(RectangleCollision *object, Vector2f center) {

    std::vector<Vector> vectors;
    std::vector<Vector2f> corners_points;
    corners_points.push_back(object->GetPointPosition('A'));
    corners_points.push_back(object->GetPointPosition('B'));
    corners_points.push_back(object->GetPointPosition('C'));
    corners_points.push_back(object->GetPointPosition('D'));

    for (int i = 0; i < 4; ++i) {

        Vector vector = {corners_points[i].x - center.x, corners_points[i].y - center.y};
        vectors.push_back(vector);
    }

    return vectors;
}

float Collision::GetProjection(Vector2f point1, Vector2f point2, Vector axis) {

    Vector vector = {point2.x - point1.x, point2.y - point1.y};
    return vector.GetDotProduct(axis);
}

float Collision::GetMinnimumProjection(std::vector<Vector> vectors, Vector axis) {

    float current_min = vectors[0].GetDotProduct(axis);

    for (int i = 1; i < vectors.size(); ++i) {

        float min = vectors[i].GetDotProduct(axis);

        if (min < current_min)
            current_min = min;
    }

    return current_min;
}

float Collision::GetMaxsimiumProjection(std::vector<Vector> vectors, Vector axis) {

    float current_max = vectors[0].GetDotProduct(axis);

    for (int i = 1; i < vectors.size(); ++i) {

        float max = vectors[i].GetDotProduct(axis);

        if (max > current_max)
            current_max = max;
    }

    return current_max;
}
