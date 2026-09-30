#pragma once
#include "exercise_04_status_effect.h"

class Burn: public StatusEffect {
public:
    Burn(const int duration);

    void tick(Character* target) override;
    const char* label() const override;
};