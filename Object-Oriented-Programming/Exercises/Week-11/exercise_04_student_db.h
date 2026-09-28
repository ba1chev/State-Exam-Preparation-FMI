#pragma once
#include "exercise_01_student.h"

class StudentDB {
protected:
    Student* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void copyFrom(const StudentDB& other);
    void moveTo(StudentDB&& other) noexcept;

public:
    StudentDB();
    StudentDB(const StudentDB& other);
    StudentDB(StudentDB&& other) noexcept;
    StudentDB& operator = (const StudentDB& other);
    StudentDB& operator = (StudentDB&& other) noexcept;
    ~StudentDB();

    void add(const Student& student);
    void remove(const char* fnId);
    const Student& findStudent(const char* fnId) const;
    void display() const;
};