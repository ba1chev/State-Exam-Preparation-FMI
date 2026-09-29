#pragma once
#include "exercise_01_exception.h"

class InvalidTemperatureException: public SensorException {
public:
    InvalidTemperatureException(const char* message);
};
