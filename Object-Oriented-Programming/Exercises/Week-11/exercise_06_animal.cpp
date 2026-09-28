#include "exercise_06_animal.h"

void Animal::free() {
    delete[] this->name;
    this->name = nullptr;
    this->age = 0;
    this->type = AnimalType::None;
}

void Animal::copyFrom(const Animal& other) {
    this->name = new char[strlen(other.name) + 1]{};
    strncpy(this->name, other.name, strlen(other.name));
    this->age = other.age;
    this->type = other.type;
}

void Animal::moveTo(Animal&& other) noexcept {
    this->name = other.name;
    this->age = other.age;
    this->type = other.type;

    other.name = nullptr;
    other.age = 0;
    other.type = AnimalType::None;
}

Animal::Animal(const char* name, const float age, AnimalType type) {
    if (!name || age < 0) {
        throw std::runtime_error("Nullptre detected or invalid age");
    }

    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
    this->age = age;
    this->type = type;
}

Animal::Animal(const Animal& other) {
    this->copyFrom(other);
}

Animal::Animal(Animal&& other) noexcept {
    this->moveTo(std::move(other));
}

Animal& Animal::operator = (const Animal& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}
    
Animal& Animal::operator = (Animal&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Animal::~Animal() {
    this->free();
}
    
const char* Animal::getName() const {
    return this->name;
}

float Animal::getAge() const {
    return this->age;
}

AnimalType Animal::getType() const {
    return this->type;
}

std::ostream& operator << (std::ostream& os, const Animal& animal) {
    os << "[Name]   " << animal.name << std::endl;
    os << "[Age]    " << animal.age << std::endl;
    os << "[Type]   ";
    switch (animal.type) {
        case AnimalType::None: {
            os << "none" << std::endl;
            break;
        }
        case AnimalType::Bird: {
            os << "bird" << std::endl;
            break;
        }
        case AnimalType::Mammal: {
            os << "mammal" << std::endl;
            break;
        }
        case AnimalType::Reptile: {
            os << "reptile" << std::endl;
            break;
        }
        default: {
            throw std::runtime_error("Unsupported animal type");
        }
    }
    return os;
}