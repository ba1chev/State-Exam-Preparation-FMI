#pragma once
#include <cstring>
#include <iostream>

enum class AnimalType {
    None, Bird, Mammal, Reptile
};

class Animal {
private:
    float age = 0.0f;
    char* name = nullptr;
    AnimalType type = AnimalType::None;

    void free();
    void copyFrom(const Animal& other);
    void moveTo(Animal&& other) noexcept;

public:
    Animal() = default;
    Animal(const char* name, const float aget, AnimalType type);
    Animal(const Animal& other);
    Animal(Animal&& other) noexcept;
    Animal& operator = (const Animal& other);
    Animal& operator = (Animal&& other) noexcept;
    ~Animal();

    const char* getName() const;
    float getAge() const;
    AnimalType getType() const;

    friend std::ostream& operator << (std::ostream& os, const Animal& animal);
};