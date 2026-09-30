#pragma once
#include "exercise_04_status_effect.h"

class Poison: public StatusEffect {
public:
    Poison(const int duration);

    void tick(Character* target) override;
    const char* label() const override;
};