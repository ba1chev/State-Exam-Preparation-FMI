#pragma once
#include <cstring>
#include <iostream>

class Ticket {
private:
    char* name = nullptr;
    float price = 0.0f;

    void free();
    void copyFrom(const Ticket& other);
    void moveTo(Ticket&& other) noexcept;

public:
    Ticket() = default;
    Ticket(const char* name, const float price);
    Ticket(const Ticket& other);
    Ticket(Ticket&& other) noexcept;
    Ticket& operator = (const Ticket& other);
    Ticket& operator = (Ticket&& other) noexcept;
    ~Ticket();

    const char* getName() const;
    float getPrice() const;
    void printData() const;
};