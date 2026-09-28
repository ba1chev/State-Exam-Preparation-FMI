#include "exercise_06_exhibit.h"

void Exhibit::free() {
    delete[] this->location;
    delete[] this->data;
    this->location = nullptr;
    this->data = nullptr;
    this->animalType = AnimalType::None;
    this->size = 0;
    this->capacity = 0;
}

void Exhibit::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater");
    }

    this->capacity = newCapacity;
    Animal* newData = new Animal[this->capacity]{};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
}

void Exhibit::moveTo(Exhibit&& other) noexcept {
    this->location = other.location;
    this->animalType = other.animalType;
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.location = nullptr;
    other.animalType = AnimalType::None;
    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

void Exhibit::copyFrom(const Exhibit& other) {
    this->location = new char[strlen(other.location) + 1]{};
    strncpy(this->location, other.location, strlen(other.location));
    this->animalType = other.animalType;
    this->capacity = other.capacity;
    this->size = other.size;
    this->data = new Animal[this->capacity]{};
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

Exhibit::Exhibit() {
    this->size = 0;
    this->capacity = 8;
    this->data = new Animal[this->capacity]{};
    this->location = new char[1]{};
}

Exhibit::Exhibit(const char* location, AnimalType animalType, const size_t capacity) {
    if (!location || capacity == 0) {
        throw std::runtime_error("Nullptr detected or invalid capacity");
    }

    this->location = new char[strlen(location) + 1]{};
    strncpy(this->location, location, strlen(location));
    this->animalType = animalType;
    this->size = 0;
    this->capacity = capacity;
    this->data = new Animal[this->capacity]{};
}

Exhibit::Exhibit(const Exhibit& other) {
    this->copyFrom(other);
}

Exhibit::Exhibit(Exhibit&& other) noexcept {
    this->moveTo(std::move(other));
}

Exhibit& Exhibit::operator = (const Exhibit& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Exhibit& Exhibit::operator = (Exhibit&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Exhibit::~Exhibit() {
    this->free();
}

void Exhibit::addAnimal(const Animal& animal) {
    if (this->isFull()) {
        throw std::runtime_error("The exhibit is full");
    }
    this->data[this->size] = animal;
    this->size += 1;
}

bool Exhibit::isFull() const {
    return this->size == this->capacity;
}

const Animal* Exhibit::search(const char* name) const {
    if (!name) {
        throw std::runtime_error("Nullptr detected");
    }

    for (size_t i = 0; i < this->size; i++) {
        if (!strcmp(this->data[i].getName(), name)) {
            return &this->data[i];
        }
    }
    return nullptr;
}

std::ostream& operator << (std::ostream& os, const Exhibit& exhibit) {
    os << "[Location] " << exhibit.location << std::endl;
    os << "[Animals]  " << exhibit.size << "/" << exhibit.capacity << std::endl;
    for (size_t i = 0; i < exhibit.size; i++) {
        os << exhibit.data[i];
    }
    return os;
}
