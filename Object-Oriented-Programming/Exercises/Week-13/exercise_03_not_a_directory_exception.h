#pragma once
#include "exercise_03_exception.h"

class NotADirectoryException: public FileSystemException {
public:
    NotADirectoryException(const char* name);
};
