#include "exercise_04_poison.h"
#include "exercise_04_character.h"
#include "exercise_04_dead_character_exception.h"
#include <stdexcept>

Poison::Poison(const int duration): StatusEffect(duration) {
    if (duration < 0) {
        throw std::runtime_error("Invalid input data");
    }
}

void Poison::tick(Character* target) {
    try {
        target->takeDirectDamage(5);
    } catch (const DeadCharacterException&) {
    }
    this->duration--;
}

const char* Poison::label() const {
    return "poisoned";
}