#include "exercise_01_human.h"

void Human::free() {
    delete[] this->name;
    this->name = nullptr;
    this->age = 0;
}

void Human::copyFrom(const Human& other) {
    this->name = new char[strlen(other.name) + 1]{};
    strncpy(this->name, other.name, strlen(other.name));
    this->age = other.age;
}

void Human::moveTo(Human&& other) noexcept {
    this->name = other.name;
    this->age = other.age;

    other.name = nullptr;
    other.age = 0;
}

Human::Human(const char* name, const size_t age) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }

    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
    this->age = age;
}

Human::Human(const Human& other) {
    this->copyFrom(other);
}

Human::Human(Human&& other) noexcept {
    this->moveTo(std::move(other));
}

Human& Human::operator = (const Human& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Human& Human::operator = (Human&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Human::~Human() {
    this->free();
}

const char* Human::getName() const {
    return this->name;
}

size_t Human::getAge() const {
    return this->age;
}