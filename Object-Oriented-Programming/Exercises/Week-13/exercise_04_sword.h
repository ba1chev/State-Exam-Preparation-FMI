#pragma once
#include "exercise_04_weapon.h"

class Sword: public Weapon {
public:
    Sword(const char* name);
    int roll() const override;
};