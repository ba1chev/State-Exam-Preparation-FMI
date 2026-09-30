#include "exercise_03_not_a_directory_exception.h"
#include <cstring>

NotADirectoryException::NotADirectoryException(const char* name):
    FileSystemException("") {
    char buffer[256]{};
    strcpy(buffer, "Not a directory: ");
    strcat(buffer, name);
    this->setMessage(buffer);
}
