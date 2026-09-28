#include "exercise_03_ticket.h"

void Ticket::free() {
    delete[] this->name;
    this->name = nullptr;
    this->price = 0;
}

void Ticket::copyFrom(const Ticket& other) {
    this->name = new char[strlen(other.name) + 1]{};
    strncpy(this->name, other.name, strlen(other.name));
    this->price = other.price;
}

void Ticket::moveTo(Ticket&& other) noexcept {
    this->name = other.name;
    this->price = other.price;

    other.name = nullptr;
    other.price = 0;
}

Ticket::Ticket(const char* name, const float price) {
    if (!name || price < 0) {
        throw std::runtime_error("Nullptr detected or price is negative");
    }

    this->name = new char[strlen(name) + 1]{};
    strncpy(this->name, name, strlen(name));
    this->price = price;
}

Ticket::Ticket(const Ticket& other) {
    this->copyFrom(other);
}

Ticket::Ticket(Ticket&& other) noexcept {
    this->moveTo(std::move(other));
}
    
Ticket& Ticket::operator = (const Ticket& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Ticket& Ticket::operator = (Ticket&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Ticket::~Ticket() {
    this->free();
}

const char* Ticket::getName() const {
    return this->name;
}

float Ticket::getPrice() const {
    return this->price;
}

void Ticket::printData() const {
    std::cout << "[Name]:   " << this->name << std::endl;
    std::cout << "[Price]:  " << this->price << std::endl;
}