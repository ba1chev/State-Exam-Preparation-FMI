// Напишете клас Vector, който моделира математически n-мерен вектор с 
// координати реални числа. За класа реализирайте:

// Конструктор по подразбиране, който създава тримерен нулев вектор.
// Конвертиращ конструктор, който създава тримерен вектор напълнен с 
// число x.
// Конструктор, който приема размер и масив от цели стойности. 
// Да се предефинират оператори за:
// Събиране на вектори.
// Изваждане на вектори.
// Умножение на вектор със скалар.
// Деление на вектор със скалар.
// Индексация.
// Дължина на вектор.
// Проверка дали векторът е нулев.
// Проверка дали векторът е равен на друг вектор.
// След семинара тази седмица допълнете с:

// Оператор <<, който приема поток за изход и извежда вектора във 
// вида (a1, a2, ..., an).
#pragma once
#include <iostream>
#include <cstring>
#include <cmath>

class Vector {
private:
    float* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void free();
    void resize(const size_t newCapacity);
    void moveTo(Vector&& other) noexcept;
    void copyFrom(const Vector& other);
    static size_t getNeededCapacity(size_t size);

public:
    Vector();
    Vector(const size_t capacity);
    Vector(const float* data, const size_t size);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    Vector& operator *= (const float scalar);
    Vector& operator /= (const float scalar);
    Vector& operator += (const Vector& other);
    Vector& operator -= (const Vector& other);
    Vector& operator = (const Vector& other);
    Vector& operator = (Vector&& other) noexcept;
    ~Vector();

    void pop();
    void pushBack(const float number);
    float& operator [](const size_t index);
    const float& operator [](const size_t index) const;

    size_t getSize() const;
    size_t getCapacity() const;
    const float* getData() const;

    friend std::ostream& operator << (std::ostream& os, const Vector& vector);
    friend std::istream& operator >> (std::istream& is, Vector& vector);
};

Vector operator + (const Vector& left, const Vector& right);
Vector operator - (const Vector& left, const Vector& right);
Vector operator * (const Vector& left, const float scalar);
Vector operator * (const float scalar, const Vector& right);
Vector operator / (const Vector& left, const float scalar);
Vector operator / (const float scalar, const Vector& right);

bool operator == (const Vector& left, const Vector& right);
bool operator != (const Vector& left, const Vector& right);
bool operator >= (const Vector& left, const Vector& right);
bool operator <= (const Vector& left, const Vector& right);
bool operator > (const Vector& left, const Vector& right);
bool operator < (const Vector& left, const Vector& right);