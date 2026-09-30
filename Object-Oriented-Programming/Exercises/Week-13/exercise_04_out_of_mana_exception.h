#pragma once
#include "exercise_04_combat_exception.h"

class OutOfManaException: public CombatException {
public:
    OutOfManaException(const char* mageName, const int missingMana);
};