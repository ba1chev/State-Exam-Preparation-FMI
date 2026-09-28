#include "exercise_05_engine.h"

Engine::Engine(const char* creatorName, const char* description, const float hoursePower):
    CarPart(creatorName, description) {
    if (hoursePower < 0) {
        throw std::runtime_error("Hourse power must be greater than zero");
    }
    this->hoursePower = hoursePower;
}

float Engine::getHoursePower() const {
    return this->hoursePower;
}

std::ostream& operator << (std::ostream& os, const Engine& engine) {
    os << (const CarPart&)engine;
    os << " | " << engine.getHoursePower() << " hp" << std::endl;
    return os;
}