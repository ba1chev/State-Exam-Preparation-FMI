#pragma once
#include <exception>

class CombatException: public std::exception {
protected:
    char message[1024];

    void setMessage(const char* message);

public:
    CombatException(const char* message);
    const char* what() const noexcept override;
};