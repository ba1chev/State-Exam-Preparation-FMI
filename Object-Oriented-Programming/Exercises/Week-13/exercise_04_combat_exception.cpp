#include "exercise_04_combat_exception.h"
#include <cstring>
#include <stdexcept>

void CombatException::setMessage(const char* message) {
    if (!message || strlen(message) >= 1024) {
        throw std::runtime_error("Nullptr detected or invalid input data");
    }
    strcpy(this->message, message);
}

CombatException::CombatException(const char* message) {
    this->setMessage(message);
}

const char* CombatException::what() const noexcept {
    return this->message;
}