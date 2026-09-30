#include "exercise_01_employee.h"

size_t Employee::idMask = 0;

void Employee::free() {
    delete[] this->name;
    this->name = nullptr;
    this->id = 0;
}

void Employee::copyFrom(const Employee& other) {
    this->name = new char[strlen(other.name) + 1]{};
    strncpy(this->name, other.name, strlen(other.name));
    this->id = other.id;
}

void Employee::moveTo(Employee&& other) noexcept {
    this->name = other.name;
    this->id = other.id;

    other.name = nullptr;
    other.id = 0;
}

Employee::Employee(const char* name) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }

    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
    this->id = idMask;
    idMask += 1;
}

Employee::Employee(const Employee& other) {
    this->copyFrom(other);
}

Employee::Employee(Employee&& other) noexcept {
    this->moveTo(std::move(other));
}

Employee& Employee::operator = (const Employee& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Employee& Employee::operator = (Employee&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Employee::~Employee() {
    this->free();
}

void Employee::printInfo() const {
    std::cout << "[Name]:   " << this->name << std::endl;
    std::cout << "[Id]:     " << this->id << std::endl;
}

const char* Employee::getName() const {
    return this->name;
}

size_t Employee::getId() const {
    return this->id;
}