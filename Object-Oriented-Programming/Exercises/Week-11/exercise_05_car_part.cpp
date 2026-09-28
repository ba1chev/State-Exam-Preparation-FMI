#include "exercise_05_car_part.h"

size_t CarPart::idMask = 0;

void CarPart::free() {
    delete[] this->creatorName;
    delete[] this->description;
    this->creatorName = nullptr;
    this->description = nullptr;
    this->id = 0;
}

void CarPart::copyFrom(const CarPart& other) {
    this->creatorName = new char[strlen(other.creatorName) + 1]{};
    this->description = new char[strlen(other.description) + 1]{};
    strncpy(this->creatorName, other.creatorName, strlen(other.creatorName));
    strncpy(this->description, other.description, strlen(other.description));
    this->id = other.id;
}

void CarPart::moveTo(CarPart&& other) noexcept {
    this->creatorName = other.creatorName;
    this->description = other.description;
    this->id = other.id;

    other.creatorName = nullptr;
    other.description = nullptr;
    other.id = 0;
}

CarPart::CarPart(const char* creatorName, const char* description) {
    if (!creatorName || !description) {
        throw std::runtime_error("Nullptr detected");
    }

    this->creatorName = new char[strlen(creatorName) + 1]{};
    this->description = new char[strlen(description) + 1]{};
    strncpy(this->creatorName, creatorName, strlen(creatorName));
    strncpy(this->description, description, strlen(description));
    idMask += 1;
    this->id = idMask;
}

CarPart::CarPart(const CarPart& other) {
    this->copyFrom(other);
}
CarPart::CarPart(CarPart&& other) noexcept {
    this->moveTo(std::move(other));
}

CarPart& CarPart::operator = (const CarPart& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

CarPart& CarPart::operator = (CarPart&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

CarPart::~CarPart() {
    this->free();
}

const char* CarPart::getCreatorName() const {
    return this->creatorName;
}
    
const char* CarPart::getDescription() const {
    return this->description;
}

size_t CarPart::getId() const {
    return this->id;
}

std::ostream& operator << (std::ostream& os, const CarPart& carPart) {
    os << "(" << carPart.getId() << ")" << " by ";
    os << "<" << carPart.getCreatorName() << ">" << " - ";
    os << carPart.getDescription();
    return os;
}