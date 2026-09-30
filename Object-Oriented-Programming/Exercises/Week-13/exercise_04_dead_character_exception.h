#pragma once
#include "exercise_04_combat_exception.h"

class DeadCharacterException: public CombatException {
public:
    DeadCharacterException(const char* characterName);
};