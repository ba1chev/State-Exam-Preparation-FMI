#include "exercise_01_id_exception.h"

InvalidSensorIdException::InvalidSensorIdException(const char* message):
    SensorException(message) {}