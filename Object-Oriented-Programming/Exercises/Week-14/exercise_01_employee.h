#pragma once
#include <cstring>
#include <iostream>

class Employee {
protected:
    char* name = nullptr;
    size_t id = 0;
    static size_t idMask;

    void free();
    void copyFrom(const Employee& other);
    void moveTo(Employee&& other) noexcept;

public:
    Employee(const char* name);
    Employee(const Employee& other);
    Employee(Employee&& other) noexcept;  
    Employee& operator = (const Employee& other);
    Employee& operator = (Employee&& other) noexcept;

    const char* getName() const;
    size_t getId() const;

    virtual ~Employee();
    virtual Employee* clone() const = 0;
    virtual void printInfo() const;
};