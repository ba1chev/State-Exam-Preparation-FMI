#pragma once
#include "exercise_01_human.h"

class Student: public Human {
private:
    char* fnId = nullptr;

    void free();
    void moveTo(Student&& other) noexcept;
    void copyFrom(const Student& other);

public:
    Student() = default;
    Student(const char* name, const char* fnId, const size_t age);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    Student& operator = (const Student& other);
    Student& operator = (Student&& other) noexcept;
    ~Student();

    void printMethod() const override;
    const char* getFnId() const;
};