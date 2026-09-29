#pragma once
#include "exercise_01_exception.h"

class FileOpenException: public SensorException {
public:
    FileOpenException(const char* message);
};
