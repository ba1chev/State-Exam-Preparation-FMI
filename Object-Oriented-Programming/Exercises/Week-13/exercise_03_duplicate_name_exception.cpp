#include "exercise_03_duplicate_name_exception.h"
#include <cstring>

DuplicateNameException::DuplicateNameException(const char* name):
    FileSystemException("") {
    char buffer[256]{};
    strcpy(buffer, "Duplicate name: ");
    strcat(buffer, name);
    this->setMessage(buffer);
}
