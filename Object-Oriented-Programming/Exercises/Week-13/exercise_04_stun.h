#pragma once
#include "exercise_04_status_effect.h"

class Stun: public StatusEffect {
public:
    Stun(const int duration);

    void tick(Character* target) override;
    const char* label() const override;
};