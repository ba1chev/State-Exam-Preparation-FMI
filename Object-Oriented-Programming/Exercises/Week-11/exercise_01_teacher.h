#pragma once
#include "exercise_01_human.h"

class Teacher: public Human {
private:
    char** subjects = nullptr;
    size_t countOfSubjects = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void copyFrom(const Teacher& other);
    void moveTo(Teacher&& other) noexcept;

public:
    Teacher() = default;
    Teacher(const char* name, const size_t age);
    Teacher(const Teacher& other);
    Teacher(Teacher&& other) noexcept;
    Teacher& operator = (const Teacher& other);
    Teacher& operator = (Teacher&& other) noexcept;
    ~Teacher();

    void addSubject(const char* newSubject);
    void printMethod() const override;
};