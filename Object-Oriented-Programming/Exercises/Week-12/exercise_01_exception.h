#pragma once
#include <stdexcept>

class SensorException: public std::invalid_argument {
public:
    SensorException(const char* message);
};