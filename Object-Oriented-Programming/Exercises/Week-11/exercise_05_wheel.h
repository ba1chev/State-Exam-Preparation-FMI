#pragma once
#include "exercise_05_car_part.h"

class Wheel: public CarPart {
private:
    float width = 0.0f;
    float profile = 0.0f;
    float diameter = 0.0f;

public:
    Wheel(const char* creatorName, const char* description,
        const float width, const float profile, const float diameter);

    float getWidth() const;
    float getProfile() const;
    float getDiameter() const;
    friend std::ostream& operator << (std::ostream& os, const Wheel& wheel);
};