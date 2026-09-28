#pragma once
#include "exercise_06_animal.h"

class Exhibit {
private:
    char* location = nullptr;
    AnimalType animalType = AnimalType::None;
    Animal* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void moveTo(Exhibit&& other) noexcept;
    void copyFrom(const Exhibit& other);

public:
    Exhibit();
    Exhibit(const char* location, AnimalType animalType, const size_t capacity);
    Exhibit(const Exhibit& other);
    Exhibit(Exhibit&& other) noexcept;
    Exhibit& operator = (const Exhibit& other);
    Exhibit& operator = (Exhibit&& other) noexcept;
    ~Exhibit();

    void addAnimal(const Animal& animal);
    bool isFull() const;
    const Animal* search(const char* name) const;

    friend std::ostream& operator << (std::ostream& os, const Exhibit& exhibit);
};
