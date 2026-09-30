#pragma once
#include "exercise_04_character.h"

class Warrior: public Character {
private:
    int armor = 0;

public:
    Warrior(const char* name, Weapon* weapon, const int armor);

    void rest() override;
    void attack(Character& target) override;
    int defend(int incomingDamage) override;
    const char* type() const override;
};