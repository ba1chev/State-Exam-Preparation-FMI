#include "exercise_04_status_effect.h"
#include <stdexcept>

StatusEffect::StatusEffect(const int duration) {
    if (duration < 0) {
        throw std::runtime_error("Invalid input data");
    }
    this->duration = duration;
}

bool StatusEffect::isExpired() const {
    return this->duration <= 0;
}