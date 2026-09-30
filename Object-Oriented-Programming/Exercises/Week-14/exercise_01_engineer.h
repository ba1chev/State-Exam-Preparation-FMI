#pragma once
#include "exercise_01_employee.h"

class Engineer: virtual public Employee {
private:
    char* techData = nullptr;

    void free();
    void copyFrom(const Engineer& other);
    void moveTo(Engineer&& other);

public:
    Engineer(const char* name, const char* techData);
    Engineer(const Engineer& other);
    Engineer(Engineer&& other) noexcept;
    Engineer& operator = (const Engineer& other);
    Engineer& operator = (Engineer&& other) noexcept;
    ~Engineer();

    void printInfo() const override;
    Employee* clone() const override;
    const char* getTechData() const;
};