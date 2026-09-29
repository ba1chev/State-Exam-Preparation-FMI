#include "exercise_01_exception.h"

SensorException::SensorException(const char* message):
    std::invalid_argument(message ? message : "Sensor error") {}