#pragma once
#include <iostream>
#include <cstring>

class Human {
protected:
    char* name = nullptr;
    size_t age = 0;

    void free();
    void copyFrom(const Human& other);
    void moveTo(Human&& other) noexcept;

public:
    Human() = default;
    Human(const char* name, const size_t age);
    Human(const Human& other);
    Human(Human&& other) noexcept;
    Human& operator = (const Human& other);
    Human& operator = (Human&& other) noexcept;
    virtual ~Human();

    const char* getName() const;
    size_t getAge() const;
    virtual void printMethod() const = 0;
};