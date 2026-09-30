#pragma once
#include "exercise_04_character.h"
#include "exercise_04_status_effect.h"

class BattleArena {
private:
    Character* first = nullptr;
    Character* second = nullptr;

    void attackWith(Character& attacker, Character& defender);

public:
    BattleArena(Character* first, Character* second);

    void runRound();
    void tickEffects();
    bool isOver() const;
    void addEffect(int characterIndex, StatusEffect* effect);
};