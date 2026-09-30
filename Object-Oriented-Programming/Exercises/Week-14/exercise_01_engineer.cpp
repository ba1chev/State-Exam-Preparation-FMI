#include "exercise_01_engineer.h"

void Engineer::free() {
    delete[] this->techData;
    this->techData = nullptr;
}

void Engineer::copyFrom(const Engineer& other) {
    this->techData = new char[strlen(other.techData) + 1]{};
    strncpy(this->techData, other.techData, strlen(other.techData));
}

void Engineer::moveTo(Engineer&& other) {
    this->techData = other.techData;
    other.techData = nullptr;
}

Engineer::Engineer(const char* name, const char* techData):
    Employee(name) {
    if (!name || !techData) {
        throw std::runtime_error("Nullptr detected");
    }
    this->techData = new char[strlen(techData) + 1]{};
    strncpy(this->techData, techData, strlen(techData));
}

Engineer::Engineer(const Engineer& other):
    Employee(other) {
    this->copyFrom(other);
}

Engineer::Engineer(Engineer&& other) noexcept:
    Employee(std::move(other)) {
    this->moveTo(std::move(other));
}

Engineer& Engineer::operator = (const Engineer& other) {
    if (this != &other) {
        Employee::free();
        this->free();
        Employee::copyFrom(other);
        this->copyFrom(other);
    }
    return *this;
}

Engineer& Engineer::operator = (Engineer&& other) noexcept {
    if (this != &other) {
        Employee::free();
        this->free();
        Employee::moveTo(std::move(other));
        this->moveTo(std::move(other));
    }
    return *this;
}

Engineer::~Engineer() {
    this->free();
}

void Engineer::printInfo() const {
    Employee::printInfo();
    std::cout << "[TechData]:   " << this->techData << std::endl;
}

const char* Engineer::getTechData() const {
    return this->techData;
}

Employee* Engineer::clone() const {
    return new Engineer(*this);
}