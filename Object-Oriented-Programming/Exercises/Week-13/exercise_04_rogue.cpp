#include "exercise_04_rogue.h"
#include "exercise_04_weapon.h"
#include "exercise_04_dagger.h"
#include "exercise_04_dagger_not_retrieved_exception.h"
#include <random>
#include <stdexcept>

Rogue::Rogue(const char* name, Weapon* weapon, const int critChance):
    Character(name, 70, weapon) {
    if (critChance < 1 || critChance > 100) {
        throw std::runtime_error("Invalid input data");
    }
    this->critChance = critChance;
}

void Rogue::rest() {
    Dagger* dagger = dynamic_cast<Dagger*>(this->weapon);
    if (dagger && dagger->getIsThrown()) {
        dagger->retrieve();
        std::cout << this->name << " retrieves his dagger" << std::endl;
    }
}

void Rogue::attack(Character& target) {
    Dagger* dagger = dynamic_cast<Dagger*>(this->weapon);
    if (dagger && dagger->getIsThrown()) {
        throw DaggerNotRetrievedException(this->name);
    }

    int raw = this->weapon->roll();

    static std::mt19937 engine{std::random_device{}()};
    std::uniform_int_distribution<int> dist{1, 100};
    if (dist(engine) <= this->critChance) {
        raw *= 2;
        std::cout << this->name << " lands a critical hit!" << std::endl;
    }

    std::cout << this->name << " strikes " << target.getName()
        << " for " << raw << " raw damage" << std::endl;
    target.takeDamage(raw);
}

int Rogue::defend(int incomingDamage) {
    return incomingDamage;
}

const char* Rogue::type() const {
    return "Rogue";
}