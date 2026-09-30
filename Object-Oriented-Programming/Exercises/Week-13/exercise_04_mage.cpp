#include "exercise_04_mage.h"
#include "exercise_04_weapon.h"
#include "exercise_04_out_of_mana_exception.h"
#include <stdexcept>

Mage::Mage(const char* name, Weapon* weapon, const int maxMana):
    Character(name, 60, weapon) {
    if (maxMana < 0) {
        throw std::runtime_error("Invalid input data");
    }
    this->maxMana = maxMana;
    this->mana = maxMana;
}

void Mage::rest() {
    this->mana += 10;
    if (this->mana > this->maxMana) {
        this->mana = this->maxMana;
    }
    std::cout << this->name << " rests and restores mana to " << this->mana << std::endl;
}

void Mage::attack(Character& target) {
    if (this->mana < 10) {
        throw OutOfManaException(this->name, 10 - this->mana);
    }
    this->mana -= 10;

    int raw = this->weapon->roll();
    std::cout << this->name << " casts a spell on " << target.getName()
        << " for " << raw << " raw damage (mana left: " << this->mana << ")" << std::endl;
    target.takeDamage(raw);
}

int Mage::defend(int incomingDamage) {
    return incomingDamage;
}

const char* Mage::type() const {
    return "Mage";
}