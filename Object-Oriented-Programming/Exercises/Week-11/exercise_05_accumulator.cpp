#include "exercise_05_accumulator.h"

void Accumulator::free() {
    delete[] this->bateryId;
    this->bateryId = nullptr;
    this->witdh = 0;
}

void Accumulator::moveTo(Accumulator&& other) noexcept {
    this->bateryId = other.bateryId;
    this->witdh = other.witdh;

    other.bateryId = nullptr;
    other.witdh = 0;
}

void Accumulator::copyFrom(const Accumulator& other) {
    this->bateryId = new char[strlen(other.bateryId) + 1]{};
    strncpy(this->bateryId, other.bateryId, strlen(other.bateryId));
    this->witdh = other.witdh;
}


Accumulator::Accumulator(const char* creatorName, const char* description, 
    const float width, const char* bateryId): CarPart(creatorName, description) {
    if (!bateryId || width < 0) {
        throw std::runtime_error("Nullptr detected or negative width param");
    }
    this->bateryId = new char[strlen(bateryId) + 1]{};
    strncpy(this->bateryId, bateryId, strlen(bateryId));
    this->witdh = width;
}

Accumulator::Accumulator(const Accumulator& other): CarPart(other) {
    this->copyFrom(other);
}

Accumulator::Accumulator(Accumulator&& other) noexcept: CarPart(std::move(other)) {
    this->moveTo(std::move(other));
}

Accumulator& Accumulator::operator = (const Accumulator& other) {
    if (this != &other) {
        CarPart::operator=(other);
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Accumulator& Accumulator::operator = (Accumulator&& other) noexcept {
    if (this != &other) {
        CarPart::operator=(std::move(other));
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Accumulator::~Accumulator() {
    this->free();
}

const char* Accumulator::getBateryId() const {
    return this->bateryId;
}

float Accumulator::getWidth() const {
    return this->witdh;
}

std::ostream& operator << (std::ostream& os, const Accumulator& wheel) {
    os << (const CarPart&)wheel;
    os << " | " << wheel.getWidth() << " Ah"
        << " [" << wheel.getBateryId() << "]" << std::endl;
    return os;
}