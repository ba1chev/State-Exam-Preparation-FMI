#include "exercise_05_wheel.h"

Wheel::Wheel(const char* creatorName, const char* description,
    const float width, const float profile, const float diameter): 
    CarPart(creatorName, description) {
    if (width < 155 || width > 365 || profile < 30 || profile > 80 ||
        diameter < 13 || diameter > 21) {
        throw std::runtime_error("Invalid constructor data");
    }
    this->width = width;
    this->diameter = diameter;
    this->profile = profile;
}

float Wheel::getWidth() const {
    return this->width;
}

float Wheel::getProfile() const {
    return this->profile;
}

float Wheel::getDiameter() const {
    return this->diameter;
}

std::ostream& operator << (std::ostream& os, const Wheel& wheel) {
    os << (const CarPart&)wheel;
    os << " | " << wheel.getWidth() << "/" << wheel.getProfile()
        << " R" << wheel.getDiameter() << std::endl;
    return os;
}