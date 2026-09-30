#pragma once
#include "exercise_04_weapon.h"

class Dagger: public Weapon {
private:
    mutable bool isThrown = false;

public:
    Dagger(const char* name);
    int roll() const override;

    void throwDagger();
    void retrieve();
    bool getIsThrown() const;
};