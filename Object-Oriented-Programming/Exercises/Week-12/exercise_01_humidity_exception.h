#pragma once
#include "exercise_01_exception.h"

class InvalidHumidityException: public SensorException {
public:
    InvalidHumidityException(const char* message);
};
