#include "exercise_04_dagger_not_retrieved_exception.h"
#include <string>
#include <stdexcept>

DaggerNotRetrievedException::DaggerNotRetrievedException(const char* rogueName):
    CombatException("temp") {
    if (!rogueName) {
        throw std::runtime_error("Nullptr detected");
    }
    this->setMessage((std::string("Rogue ") + std::string(rogueName)
        + std::string(" has not retrieved his dagger")).c_str());
}