#pragma once
#include "exercise_04_character.h"

class Rogue: public Character {
private:
    int critChance = 0;

public:
    Rogue(const char* name, Weapon* weapon, const int critChance);

    void rest() override;
    void attack(Character& target) override;
    int defend(int incomingDamage) override;
    const char* type() const override;
};