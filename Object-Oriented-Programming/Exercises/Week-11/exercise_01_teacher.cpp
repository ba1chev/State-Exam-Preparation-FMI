#include "exercise_01_teacher.h"

void Teacher::free() {
    for (size_t i = 0; i < this->countOfSubjects; i++) {
        delete[] this->subjects[i];
        this->subjects[i] = nullptr;
    }
    delete[] this->subjects;
    this->subjects = nullptr;
    this->countOfSubjects = 0;
    this->capacity = 0;
}

void Teacher::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater than the old one");
    }

    this->capacity = newCapacity;
    char** newSubjects = new char* [this->capacity]{nullptr};
    for (size_t i = 0; i < this->countOfSubjects; i++) {
        newSubjects[i] = this->subjects[i];
        this->subjects[i] = nullptr;
    }
    delete[] this->subjects;
    this->subjects = newSubjects;
}

void Teacher::copyFrom(const Teacher& other) {
    this->capacity = other.capacity;
    this->countOfSubjects = other.countOfSubjects;
    this->subjects = new char* [this->capacity]{nullptr};
    for (size_t i = 0; i < this->countOfSubjects; i++) {
        this->subjects[i] = new char[strlen(other.subjects[i]) + 1]{};
        strncpy(this->subjects[i], other.subjects[i], strlen(other.subjects[i]));
    }
}

void Teacher::moveTo(Teacher&& other) noexcept {
    this->subjects = other.subjects;
    this->capacity = other.capacity;
    this->countOfSubjects = other.countOfSubjects;

    other.subjects = nullptr;
    other.capacity = 0;
    other.countOfSubjects = 0;
}

Teacher::Teacher(const char* name, const size_t age): Human(name, age) {
    this->capacity = 8;
    this->countOfSubjects = 0;
    this->subjects = new char* [this->capacity]{nullptr};
}

Teacher::Teacher(const Teacher& other): Human(other) {
    this->copyFrom(other);
}

Teacher::Teacher(Teacher&& other) noexcept: Human(std::move(other)) {
    this->moveTo(std::move(other));
}

Teacher& Teacher::operator = (const Teacher& other) {
    if (this != &other) {
        this->free();
        Human::free();
        this->copyFrom(other);
        Human::copyFrom(other);
    }
    return *this;
}

Teacher& Teacher::operator = (Teacher&& other) noexcept {
    if (this != &other) {
        this->free();
        Human::free();
        this->moveTo(std::move(other));
        Human::moveTo(std::move(other));
    }
    return *this;
}

Teacher::~Teacher() {
    this->free();
}

void Teacher::addSubject(const char* newSubject) {
    if (this->countOfSubjects == this->capacity) {
        this->resize(this->countOfSubjects * 2);
    }
    this->subjects[this->countOfSubjects] = new char[strlen(newSubject) + 1]{};
    strncpy(this->subjects[this->countOfSubjects], newSubject, strlen(newSubject));
    this->countOfSubjects += 1;
}

void Teacher::printMethod() const {
    std::cout << "[Name]    " << this->getName() << std::endl;
    std::cout << "[Age]     " << this->getAge() << std::endl;
    std::cout << "[Subjects]" << "{ ";
    for (size_t i = 0; i < this->countOfSubjects; i++) {
        std::cout << this->subjects[i] << " ";
    }
    std::cout << "}" << std::endl; 
}