#include "exercise_01_timestamp_exception.h"

InvalidTimestampException::InvalidTimestampException(const char* message):
    SensorException(message) {}
