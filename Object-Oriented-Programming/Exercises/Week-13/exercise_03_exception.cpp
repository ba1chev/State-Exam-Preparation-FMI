#include "exercise_03_exception.h"
#include <cstring>

void FileSystemException::setMessage(const char* message) {
    delete[] this->message;
    this->message = new char[strlen(message) + 1]{};
    strncpy(this->message, message, strlen(message));
}

FileSystemException::FileSystemException(const char* message) {
    this->setMessage(message);
}

FileSystemException::FileSystemException(const FileSystemException& other) {
    this->setMessage(other.message);
}

FileSystemException& FileSystemException::operator = (const FileSystemException& other) {
    if (this != &other) {
        this->setMessage(other.message);
    }
    return *this;
}

FileSystemException::~FileSystemException() {
    delete[] this->message;
}

const char* FileSystemException::what() const noexcept {
    return this->message;
}
