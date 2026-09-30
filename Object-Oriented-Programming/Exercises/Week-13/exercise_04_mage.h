#pragma once
#include "exercise_04_character.h"

class Mage: public Character {
private:
    int mana = 0;
    int maxMana = 0;

public:
    Mage(const char* name, Weapon* weapon, const int maxMana);

    void rest() override;
    void attack(Character& target) override;
    int defend(int incomingDamage) override;
    const char* type() const override;
};