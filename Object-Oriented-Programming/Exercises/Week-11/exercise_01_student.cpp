#include "exercise_01_student.h"

void Student::free() {
    delete[] this->fnId;
    this->fnId = nullptr;
}

void Student::moveTo(Student&& other) noexcept {
    this->fnId = other.fnId;
    other.fnId = nullptr;
}

void Student::copyFrom(const Student& other) {
    this->fnId = new char[strlen(other.fnId) + 1]{};
    strncpy(this->fnId, other.fnId, strlen(other.fnId));
}
    
Student::Student(const char* name, const char* fdId, const size_t age): Human(name, age) {
    if (!fdId || strlen(fdId) != 10) {
        throw std::runtime_error("Nullptr detected or invalid input data");
    }

    this->fnId = new char[strlen(fdId) + 1]{};
    strncpy(this->fnId, fdId, strlen(fdId));
}

Student::Student(const Student& other): Human(other) {
    this->copyFrom(other);
}

Student::Student(Student&& other) noexcept: Human(std::move(other)) {
    this->moveTo(std::move(other));
}

Student& Student::operator = (const Student& other) {
    if (this != &other) {
        this->free();
        Human::free();
        this->copyFrom(other);
        Human::copyFrom(other);
    }
    return *this;
}

Student& Student::operator = (Student&& other) noexcept {
    if (this != &other) {
        this->free();
        Human::free();
        this->moveTo(std::move(other));
        Human::moveTo(std::move(other));
    }
    return *this;
}

Student::~Student() {
    this->free();
}

const char* Student::getFnId() const {
    return this->fnId;
}

void Student::printMethod() const {
    std::cout << "[Name]" << this->getName() << std::endl;
    std::cout << "[Age] " << this->getAge() << std::endl;
    std::cout << "[FnId]" << this->getFnId() << std::endl;
}