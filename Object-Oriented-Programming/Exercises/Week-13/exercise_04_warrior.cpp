#include "exercise_04_warrior.h"
#include "exercise_04_weapon.h"
#include <stdexcept>

Warrior::Warrior(const char* name, Weapon* weapon, const int armor):
    Character(name, 80, weapon) {
    if (armor < 0) {
        throw std::runtime_error("Invalid input data");
    }
    this->armor = armor;
}

void Warrior::rest() {
    this->hp += 5;
    if (this->hp > this->maxHp) {
        this->hp = this->maxHp;
    }
}

void Warrior::attack(Character& target) {
    int raw = this->weapon->roll();
    std::cout << this->name << " attacks " << target.getName()
        << " for " << raw << " raw damage" << std::endl;
    target.takeDamage(raw);
}

int Warrior::defend(int incomingDamage) {
    int result = incomingDamage - this->armor;
    if (result < 0) {
        result = 0;
    }
    std::cout << this->name << " blocks with armor " << this->armor
        << ": " << incomingDamage << " -> " << result << std::endl;
    return result;
}

const char* Warrior::type() const {
    return "Warrior";
}