#include "exercise_01_humidity_exception.h"

InvalidHumidityException::InvalidHumidityException(const char* message):
    SensorException(message) {}
