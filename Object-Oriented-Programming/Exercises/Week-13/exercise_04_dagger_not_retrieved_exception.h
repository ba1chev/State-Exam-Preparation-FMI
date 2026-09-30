#pragma once
#include "exercise_04_combat_exception.h"

class DaggerNotRetrievedException: public CombatException {
public:
    DaggerNotRetrievedException(const char* rogueName);
};
