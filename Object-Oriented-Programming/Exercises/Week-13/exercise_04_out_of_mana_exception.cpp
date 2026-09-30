#include "exercise_04_out_of_mana_exception.h"
#include <string>
#include <stdexcept>

OutOfManaException::OutOfManaException(const char* mageName, const int missingMana):
    CombatException("temp") {
    if (!mageName) {
        throw std::runtime_error("Nullptr detected");
    }
    this->setMessage((std::string("Mage ") + std::string(mageName)
        + std::string(" is out of mana, missing ") + std::to_string(missingMana)
        + std::string(" mana")).c_str());
}