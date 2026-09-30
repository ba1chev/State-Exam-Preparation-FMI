#include "exercise_01_firm.h"

void Firm::free() {
    for (size_t i = 0; i < this->size; i++) {
        delete this->data[i];
        this->data[i] = nullptr;
    }
    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

void Firm::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greter than the old one");
    }
    this->capacity = newCapacity;
    Employee** newData = new Employee*[this->capacity]{nullptr};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
        this->data[i] = nullptr;
    }
    delete[] this->data;
    this->data = newData;
}

void Firm::copyFrom(const Firm& other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new Employee*[this->capacity]{nullptr};
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i]->clone();
    }
}

void Firm::moveTo(Firm&& other) noexcept {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = other.data;
    
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

Firm::Firm() {
    this->size = 0;
    this->capacity = 8;
    this->data = new Employee*[this->capacity]{nullptr};
}

Firm::Firm(const Firm& other) {
    this->copyFrom(other);
}

Firm::Firm(Firm&& other) {
    this->moveTo(std::move(other));
}

Firm& Firm::operator = (const Firm& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Firm& Firm::operator = (Firm&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Firm::~Firm() {
    this->free();
}

void Firm::addEmployee(Employee* employee) {
    if (!employee) {
        throw std::runtime_error("Nullptr detected");
    }
    if (this->size == this->capacity) {
        this->resize(this->size * 2);
    }
    this->data[this->size] = employee->clone();
    this->size += 1;
}

void Firm::removeEmployee(const size_t id) {
    if (this->size == 0) {
        throw std::runtime_error("The container is empty");
    }

    int foundIndex = -1;
    for (size_t i = 0; i < this->size; i++) {
        if (this->data[i]->getId() == id) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        delete this->data[foundIndex];
        for (size_t i = foundIndex; i < this->size - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->size -= 1;
    } else {
        throw std::runtime_error("Not found");
    }
}

void Firm::printInfo() const {
    for (size_t i = 0; i < this->size; i++) {
        this->data[i]->printInfo();
    }
}

const Employee* const* Firm::getData() const {
    return this->data;
}

size_t Firm::getSize() const {
    return this->size;
}

size_t Firm::getCapacity() const {
    return this->capacity;
}