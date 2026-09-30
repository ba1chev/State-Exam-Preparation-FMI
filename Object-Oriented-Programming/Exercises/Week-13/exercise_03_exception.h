#pragma once
#include <exception>

class FileSystemException: public std::exception {
protected:
    char* message = nullptr;

    void setMessage(const char* message);

public:
    FileSystemException(const char* message);
    FileSystemException(const FileSystemException& other);
    FileSystemException& operator = (const FileSystemException& other);
    ~FileSystemException();

    const char* what() const noexcept override;
};
