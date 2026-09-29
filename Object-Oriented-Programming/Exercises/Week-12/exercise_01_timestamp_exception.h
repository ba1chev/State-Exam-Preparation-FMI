#pragma once
#include "exercise_01_exception.h"

class InvalidTimestampException: public SensorException {
public:
    InvalidTimestampException(const char* message);
};
