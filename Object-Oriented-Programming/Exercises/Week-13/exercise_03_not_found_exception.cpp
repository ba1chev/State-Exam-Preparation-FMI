#include "exercise_03_not_found_exception.h"
#include <cstring>

NodeNotFoundException::NodeNotFoundException(const char* name):
    FileSystemException("") {
    char buffer[256]{};
    strcpy(buffer, "Node not found: ");
    strcat(buffer, name);
    this->setMessage(buffer);
}
