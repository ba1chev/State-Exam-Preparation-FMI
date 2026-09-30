#pragma once
#include "exercise_01_employee.h"

class Firm {
private:
    Employee** data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void copyFrom(const Firm& other);
    void moveTo(Firm&& other) noexcept;

public:
    Firm();
    Firm(const Firm& other);
    Firm(Firm&& other);
    Firm& operator = (const Firm& other);
    Firm& operator = (Firm&& other) noexcept;
    ~Firm();

    void addEmployee(Employee* employee);
    void removeEmployee(const size_t id);
    void printInfo() const;

    const Employee* const* getData() const;
    size_t getSize() const;
    size_t getCapacity() const;
};