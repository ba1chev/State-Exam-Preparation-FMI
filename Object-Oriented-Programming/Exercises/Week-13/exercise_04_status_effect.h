#pragma once

class Character;

class StatusEffect {
protected:
    int duration = 0;

public:
    StatusEffect(const int duration);
    bool isExpired() const;

    virtual ~StatusEffect() = default;
    virtual void tick(Character* target) = 0;
    virtual const char* label() const = 0;
};