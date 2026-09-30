#pragma once
#include <cstring>
#include <iostream>

class StatusEffect;
class Weapon;

class Character {
protected:
    char* name = nullptr;
    int hp = 0;
    int maxHp = 0;
    Weapon* weapon = nullptr;

    StatusEffect** effects = nullptr;
    size_t effectsCount = 0;
    size_t effectsCapacity = 0;

    bool stunned = false;
    int damageReduction = 0;

    void free();
    void copyFrom(const Character& other);
    void moveTo(Character&& other) noexcept;

    void resize(size_t newCapacity);

public:
    Character(const char* name, const int maxHp, Weapon* weapon);
    Character(const Character& other);
    Character(Character&& other) noexcept;
    Character& operator = (const Character& other);
    Character& operator = (Character&& other) noexcept;

    virtual ~Character();

    virtual void rest() = 0;
    virtual void attack(Character& target) = 0;
    virtual int defend(int incomingDamage) = 0;
    virtual const char* type() const = 0;

    void takeDamage(int amount);
    void takeDirectDamage(int amount);
    bool isDead() const;

    void addEffect(StatusEffect* effect);
    void tickEffects();

    bool isStunned() const;
    void setStunned(bool value);
    void addDamageReduction(int amount);

    const char* getName() const;
    virtual std::string statusLine() const;
};