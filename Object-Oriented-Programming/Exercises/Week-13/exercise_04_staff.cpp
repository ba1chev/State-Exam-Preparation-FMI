#include "exercise_04_staff.h"
#include <random>
#include <stdexcept>

Staff::Staff(const int maxMana, const char* name): Weapon(name) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }
    if (maxMana < 5) {
        throw std::runtime_error("Invalid input data");
    }
    this->maxMana = maxMana;
}

int Staff::roll() const {
    static std::mt19937 engine{std::random_device{}()};
    std::uniform_int_distribution<int> dist{1, this->maxMana / 5};
    return dist(engine);
}