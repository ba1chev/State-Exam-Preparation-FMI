#include "exercise_01_manager.h"

void Manager::free() {
    delete[] this->project;
    this->project = nullptr;
}

void Manager::copyFrom(const Manager& other) {
    this->project = new char[strlen(other.project) + 1]{};
    strncpy(this->project, other.project, strlen(other.project));
}

void Manager::moveTo(Manager&& other) noexcept {
    this->project = other.project;
    other.project = nullptr;
}

Manager::Manager(const char* name, const char* project):
    Employee(name) {
    if (!name || !project) {
        throw std::runtime_error("Nullptr detected");
    }
    this->project = new char[strlen(project) + 1]{};
    strncpy(this->project, project, strlen(project));
}

Manager::Manager(const Manager& other):
    Employee(other) {
    this->copyFrom(other);
}

Manager::Manager(Manager&& other) noexcept:
    Employee(std::move(other)) {
    this->moveTo(std::move(other));
}

Manager& Manager::operator = (const Manager& other) {
    if (this != &other) {
        Employee::free();
        this->free();
        Employee::copyFrom(other);
        this->copyFrom(other);
    }
    return *this;
}

Manager& Manager::operator = (Manager&& other) noexcept {
    if (this != &other) {
        Employee::free();
        this->free();
        Employee::moveTo(std::move(other));
        this->moveTo(std::move(other));
    }
    return *this;
}

Manager::~Manager() {
    this->free();
}

const char* Manager::getProject() const {
    return this->project;
}

void Manager::printInfo() const {
    Employee::printInfo();
    std::cout << "[Project]:    " << this->project << std::endl;
}

Employee* Manager::clone() const {
    return new Manager(*this);
}