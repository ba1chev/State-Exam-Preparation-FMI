#include "exercise_04_dagger.h"
#include <random>
#include <stdexcept>

Dagger::Dagger(const char* name): Weapon(name) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }
    this->isThrown = false;
}

int Dagger::roll() const {
    static std::mt19937 engine{std::random_device{}()};
    if (this->isThrown) {
        std::uniform_int_distribution<int> dist{1 * 5, (int)(20 * 1.5)};
        return dist(engine);
    }
    std::uniform_int_distribution<int> dist{1, 20};
    return dist(engine);
}

void Dagger::throwDagger() {
    this->isThrown = true;
}

void Dagger::retrieve() {
    this->isThrown = false;
}

bool Dagger::getIsThrown() const {
    return this->isThrown;
}