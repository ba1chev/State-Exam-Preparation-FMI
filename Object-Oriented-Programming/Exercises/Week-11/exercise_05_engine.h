#pragma once
#include "exercise_05_car_part.h"

class Engine: public CarPart {
private:
    float hoursePower = 0.0f;
public:
    Engine(const char* creatorName, const char* description, const float hoursePower);

    float getHoursePower() const;
    friend std::ostream& operator << (std::ostream& os, const Engine& engine);
};