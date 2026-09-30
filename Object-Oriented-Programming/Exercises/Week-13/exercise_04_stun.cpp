#include "exercise_04_stun.h"
#include "exercise_04_character.h"
#include <stdexcept>

Stun::Stun(const int duration): StatusEffect(duration) {
    if (duration < 0) {
        throw std::runtime_error("Invalid input data");
    }
}

void Stun::tick(Character* target) {
    target->setStunned(true);
    this->duration--;
}

const char* Stun::label() const {
    return "stunned";
}