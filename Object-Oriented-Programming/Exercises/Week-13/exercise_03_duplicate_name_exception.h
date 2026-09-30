#pragma once
#include "exercise_03_exception.h"

class DuplicateNameException: public FileSystemException {
public:
    DuplicateNameException(const char* name);
};
