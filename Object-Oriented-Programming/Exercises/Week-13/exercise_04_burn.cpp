#include "exercise_04_burn.h"
#include "exercise_04_character.h"
#include "exercise_04_dead_character_exception.h"
#include <stdexcept>

Burn::Burn(const int duration): StatusEffect(duration) {
    if (duration < 0) {
        throw std::runtime_error("Invalid input data");
    }
}

void Burn::tick(Character* target) {
    try {
        target->takeDirectDamage(8);
    } catch (const DeadCharacterException&) {
    }
    target->addDamageReduction(3);
    this->duration--;
}

const char* Burn::label() const {
    return "burning";
}