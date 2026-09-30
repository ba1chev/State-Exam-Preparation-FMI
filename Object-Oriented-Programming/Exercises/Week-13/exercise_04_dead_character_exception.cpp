#include "exercise_04_dead_character_exception.h"
#include <string>
#include <stdexcept>

DeadCharacterException::DeadCharacterException(const char* characterName):
    CombatException("temp") {
    if (!characterName) {
        throw std::runtime_error("Nullptr detected");
    }
    this->setMessage((std::string("Character ") + std::string(characterName)
        + std::string(" is already dead")).c_str());
}