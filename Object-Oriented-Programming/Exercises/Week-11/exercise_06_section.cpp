#include "exercise_06_section.h"
#include "exercise_06_zoo_keeper.h"
#include <cstring>

void Section::free() {
    delete[] this->name;
    delete[] this->data;
    this->name = nullptr;
    this->data = nullptr;
    this->minExpirience = 0;
    this->size = 0;
    this->capacity = 0;
    this->guard = nullptr;
}

void Section::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater");
    }

    this->capacity = newCapacity;
    Exhibit* newData = new Exhibit[this->capacity]{};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
}

void Section::moveTo(Section&& other) noexcept {
    this->name = other.name;
    this->minExpirience = other.minExpirience;
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;
    this->guard = other.guard;

    other.name = nullptr;
    other.minExpirience = 0;
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
    other.guard = nullptr;
}

void Section::copyFrom(const Section& other) {
    this->name = new char[strlen(other.name) + 1]{};
    strncpy(this->name, other.name, strlen(other.name));
    this->minExpirience = other.minExpirience;
    this->capacity = other.capacity;
    this->size = other.size;
    this->data = new Exhibit[this->capacity]{};
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
    this->guard = nullptr;
}

Section::Section() {
    this->minExpirience = 0;
    this->size = 0;
    this->capacity = 8;
    this->data = new Exhibit[this->capacity]{};
    this->name = new char[1]{};
    this->guard = nullptr;
}

Section::Section(const char* name, const size_t minExpirience) {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }

    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
    this->minExpirience = minExpirience;
    this->size = 0;
    this->capacity = 8;
    this->data = new Exhibit[this->capacity]{};
    this->guard = nullptr;
}

Section::Section(const Section& other) {
    this->copyFrom(other);
}

Section::Section(Section&& other) noexcept {
    this->moveTo(std::move(other));
}

Section& Section::operator = (const Section& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Section& Section::operator = (Section&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Section::~Section() {
    this->free();
}

void Section::addExhibit(const Exhibit& exhibit) {
    if (this->size == this->capacity) {
        this->resize(this->size * 2);
    }
    this->data[this->size] = exhibit;
    this->size += 1;
}

bool Section::assignGuard(ZooKeeper* keeper) {
    if (!keeper || keeper->getExperience() < this->minExpirience) {
        return false;
    }
    this->guard = keeper;
    return true;
}

bool Section::hasActiveGuard() const {
    return this->guard != nullptr;
}

void Section::releaseGuard(const ZooKeeper* keeper) {
    if (this->guard == keeper) {
        this->guard = nullptr;
    }
}

const Animal* Section::search(const char* name) const {
    for (size_t i = 0; i < this->size; i++) {
        const Animal* found = this->data[i].search(name);
        if (found) {
            return found;
        }
    }
    return nullptr;
}

const char* Section::getName() const {
    return this->name;
}

size_t Section::getMinExpirience() const {
    return this->minExpirience;
}

const Exhibit* Section::getExhibitData() const {
    return this->data;
}

size_t Section::getExhibitDataSize() const {
    return this->size;
}

std::ostream& operator << (std::ostream& os, const Section& section) {
    os << "=== Section: " << section.name
        << " (min experience " << section.minExpirience << ") ===" << std::endl;
    os << "[Guard]    ";
    if (section.guard) {
        os << section.guard->getName() << std::endl;
    } else {
        os << "none" << std::endl;
    }
    for (size_t i = 0; i < section.size; i++) {
        os << section.data[i];
    }
    return os;
}
