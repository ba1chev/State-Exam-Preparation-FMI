#pragma once
#include <stdexcept>

class EmptyStackException: public std::runtime_error {
public:
    EmptyStackException(const char* message): std::runtime_error(message) {}
};
