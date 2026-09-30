#include "exercise_04_weapon.h"

void Weapon::free() {
    delete[] this->name;
    this->name = nullptr;
}

void Weapon::copyFrom(const Weapon& other) {
    this->name = new char[strlen(other.name) + 1]{};
    strncpy(this->name, other.name, strlen(other.name));
}

void Weapon::moveTo(Weapon&& other) noexcept {
    this->name = other.name;
    other.name = nullptr;
}

Weapon::Weapon(const char* name) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }
    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
}

Weapon::Weapon(const Weapon& other) {
    this->copyFrom(other);
}

Weapon::Weapon(Weapon&& other) noexcept {
    this->moveTo(std::move(other));
}

Weapon& Weapon::operator = (const Weapon& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Weapon& Weapon::operator = (Weapon&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Weapon::~Weapon() {
    delete[] this->name;
    this->name = nullptr;
}

const char* Weapon::getName() const {
    return this->name;
}