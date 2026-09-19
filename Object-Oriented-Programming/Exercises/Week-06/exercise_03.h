// Създайте клас Polynomial, който моделира работа с полином.

// Полиномът има вида:

// P(x) = a₀ + a₁x + a₂x² + ... + aₙxⁿ

// Коефициентите на полинома трябва да се съхраняват в динамичен масив.

// В конструктора на класа ще приемате цяло число n, което представлява степента на полинома. 
// Полиномът трябва да има n + 1 коефициента (от a₀ до aₙ).

// Трябва да реализирате следните функционалности:

// Задаване на коефициент на дадена степен.
// Връщане на коефициент на дадена степен.
// Пресмятане на стойността на полинома при подадена стойност x.
// Функция за извеждане на полинома в подходящ текстов вид.
// статична функция createConstant(double), която връща полином константа.
// Работата с паметта трябва да бъде реализирана коректно.

// При копиране на обекти трябва да се гарантира, че:

// Всеки обект притежава собствено копие на динамичния масив.
// Не трябва да се допуска споделяне на памет между различни обекти.
#pragma once
#include <iostream>

class Polynomial {
private:
    float* coefficents = nullptr;
    size_t degree = 0;

    void free();
    void resize(const size_t newDegree);
    void copyFrom(const Polynomial& other);
    void moveTo(Polynomial&& other) noexcept;

public:
    Polynomial();
    Polynomial(const size_t degree);
    Polynomial(const Polynomial& other);
    Polynomial(Polynomial&& other) noexcept;
    Polynomial& operator = (const Polynomial& other);
    Polynomial& operator = (Polynomial&& other) noexcept;
    ~Polynomial();

    void setCoeffAtCurrentDegree(const size_t targetDegree, const float coeff);
    float getCoeffAtCurrentDegree(const size_t targetDegree) const;
    float evaluate(const float x) const;

    static Polynomial createConstant(const double value);
    friend std::ostream& operator << (std::ostream& os, const Polynomial& poly);
};