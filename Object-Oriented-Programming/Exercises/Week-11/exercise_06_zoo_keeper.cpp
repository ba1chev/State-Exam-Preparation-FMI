#include "exercise_06_zoo_keeper.h"

void ZooKeeper::free() {
    delete[] this->name;
    this->name = nullptr;
    this->employeeID = 0;
    this->experience = 0;
}

void ZooKeeper::copyFrom(const ZooKeeper& other) {
    this->name = new char[strlen(other.name) + 1]{};
    strncpy(this->name, other.name, strlen(other.name));
    this->employeeID = other.employeeID;
    this->experience = other.experience;
}

void ZooKeeper::moveTo(ZooKeeper&& other) noexcept {
    this->name = other.name;
    this->employeeID = other.employeeID;
    this->experience = other.experience;

    other.name = nullptr;
    other.employeeID = 0;
    other.experience = 0;
}

ZooKeeper::ZooKeeper(const char* name, const size_t employeeID, const size_t experience) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }

    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
    this->employeeID = employeeID;
    this->experience = experience;
}

ZooKeeper::ZooKeeper(const ZooKeeper& other) {
    this->copyFrom(other);
}

ZooKeeper::ZooKeeper(ZooKeeper&& other) noexcept {
    this->moveTo(std::move(other));
}

ZooKeeper& ZooKeeper::operator = (const ZooKeeper& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

ZooKeeper& ZooKeeper::operator = (ZooKeeper&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

ZooKeeper::~ZooKeeper() {
    this->free();
}

const char* ZooKeeper::getName() const {
    return this->name;
}

size_t ZooKeeper::getEmployeeID() const {
    return this->employeeID;
}

size_t ZooKeeper::getExperience() const {
    return this->experience;
}

std::ostream& operator << (std::ostream& os, const ZooKeeper& keeper) {
    os << "[Keeper]     " << keeper.name << std::endl;
    os << "[EmployeeID] " << keeper.employeeID << std::endl;
    os << "[Experience] " << keeper.experience << std::endl;
    return os;
}
