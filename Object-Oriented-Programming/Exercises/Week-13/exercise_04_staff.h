#pragma once
#include "exercise_04_weapon.h"

class Staff: public Weapon {
private:
    int maxMana = 0;

public:
    Staff(const int maxMana, const char* name);
    int roll() const override;
};