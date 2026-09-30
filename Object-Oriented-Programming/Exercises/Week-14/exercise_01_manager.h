#pragma once
#include "exercise_01_employee.h"

class Manager: virtual public Employee {
private:
    char* project = nullptr;

    void free();
    void copyFrom(const Manager& other);
    void moveTo(Manager&& other) noexcept;

public:
    Manager(const char* name, const char* project);
    Manager(const Manager& other);
    Manager(Manager&& other) noexcept;
    Manager& operator = (const Manager& other);
    Manager& operator = (Manager&& other) noexcept;
    ~Manager();

    void printInfo() const override;
    Employee* clone() const override;
    const char* getProject() const;
};