#include "exercise_04_sword.h"

Sword::Sword(const char* name): Weapon(name) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }
}

int Sword::roll() const {
    return 10;
}