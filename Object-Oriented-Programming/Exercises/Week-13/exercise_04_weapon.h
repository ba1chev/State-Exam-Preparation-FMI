#pragma once
#include <cstring>
#include <iostream>

class Weapon {
protected:
    char* name = nullptr;

    void free();
    void copyFrom(const Weapon& other);
    void moveTo(Weapon&& other) noexcept;

public:
    Weapon(const char* name);
    Weapon(const Weapon& other);
    Weapon(Weapon&& other) noexcept;
    Weapon& operator = (const Weapon& other);
    Weapon& operator = (Weapon&& other) noexcept;

    virtual ~Weapon();
    virtual int roll() const = 0;

    const char* getName() const;
};
