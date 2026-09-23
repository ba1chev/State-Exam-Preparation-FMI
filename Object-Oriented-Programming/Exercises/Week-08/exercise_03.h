// Напишете клас Rational, който моделира рационално число (дроб) p/q с целочислени числител и знаменател. За класа реализирайте:

// Конструктор по подразбиране, който създава дробта 0/1

// Конструктор с един параметър int n — създава n/1

// Конструктор с два параметъра int num, int den

// Дробта винаги се съхранява в съкратен вид с положителен знаменател (използвайте НОД)

// Да се предефинират оператори за:

// Събиране, изваждане, умножение и деление на дроби (+, -, *, /)
// Съставно присвояване (+=, -=, *=, /=)
// Унарен минус
// Явно преобразуване към double
// Проверка дали дробта е ненулева (operator bool)
// След семинара тази седмица допълнете с:

// Сравнение (== и <=>)
// Инкремент и декремент — pre и post (++, --)
// Вход и изход от потоци (<< извежда като p/q, или само p ако q == 1)
#pragma once
#include <iostream>
#include <cmath>

static int GCD(const int left, const int right);
static int LCM(const int left, const int right);

class Rational {
private:
    int numerator = 0;
    int denominator = 1;

    void simplify();

public:
    Rational() = default;
    Rational(const int number);
    Rational(const int numerator, const int denominator);

    Rational& operator += (const Rational& other);
    Rational& operator -= (const Rational& other);
    Rational& operator *= (const Rational& other);
    Rational& operator /= (const Rational& other);

    Rational& operator ++ ();
    Rational& operator -- ();
    Rational operator ++ (int dummy);
    Rational operator -- (int dummy);

    Rational operator - () const;

    explicit operator double() const;
    explicit operator bool() const;

    int getNumerator() const;
    int getDenominator() const;
    Rational getReciprocal() const;

    friend std::ostream& operator << (std::ostream& os, const Rational& number);
    friend std::istream& operator >> (std::istream& is, Rational& number);
};

Rational operator + (const Rational& left, const Rational& right);
Rational operator - (const Rational& left, const Rational& right);
Rational operator * (const Rational& left, const Rational& right);
Rational operator / (const Rational& left, const Rational& right);

bool operator == (const Rational& left, const Rational& right);
bool operator != (const Rational& left, const Rational& right);
bool operator >= (const Rational& left, const Rational& right);
bool operator <= (const Rational& left, const Rational& right);
bool operator > (const Rational& left, const Rational& right);
bool operator < (const Rational& left, const Rational& right);
