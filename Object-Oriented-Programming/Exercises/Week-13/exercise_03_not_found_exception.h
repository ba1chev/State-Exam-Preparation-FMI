#pragma once
#include "exercise_03_exception.h"

class NodeNotFoundException: public FileSystemException {
public:
    NodeNotFoundException(const char* name);
};
