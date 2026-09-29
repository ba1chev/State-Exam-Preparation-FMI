#include "exercise_01_temperature_exception.h"

InvalidTemperatureException::InvalidTemperatureException(const char* message):
    SensorException(message) {}
