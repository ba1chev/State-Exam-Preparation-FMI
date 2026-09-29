#pragma once
#include "exercise_01_exception.h"

class InvalidSensorIdException: public SensorException {
public:
    InvalidSensorIdException(const char* message);
};