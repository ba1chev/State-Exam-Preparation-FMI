#include "exercise_03.h"

void Rational::simplify() {
    if (this->denominator < 0) {
        this->numerator = -this->numerator;
        this->denominator = -this->denominator;
    }

    int gcd = GCD(std::abs(this->numerator), this->denominator);
    if (gcd == 0) {
        return;
    }
    this->numerator /= gcd;
    this->denominator /= gcd;
}

int GCD(const int left, const int right) {
    if (right == 0) {
        return left;
    }
    return GCD(right, left % right);
}

int LCM(const int left, const int right) {
    return std::abs(left * right) / GCD(left, right);
}

Rational::Rational(const int number) {
    this->numerator = number;
    this->denominator = 1;
}

Rational::Rational(const int numerator, const int denominator) {
    if (denominator == 0) {
        throw std::runtime_error("Zero devision is not allowed");
    }

    this->numerator = numerator;
    this->denominator = denominator;
    this->simplify();
}

Rational& Rational::operator += (const Rational& other) {
    int sharedDenominator = LCM(this->denominator, other.denominator);
    int multiplierLeft = sharedDenominator / this->denominator;
    int multiplierRight = sharedDenominator / other.denominator;
    this->numerator *= multiplierLeft;
    this->numerator += other.numerator * multiplierRight;
    this->denominator = sharedDenominator;
    this->simplify();

    return *this;
}

Rational& Rational::operator -= (const Rational& other) {
    int sharedDenominator = LCM(this->denominator, other.denominator);
    int multiplierLeft = sharedDenominator / this->denominator;
    int multiplierRight = sharedDenominator / other.denominator;
    this->numerator *= multiplierLeft;
    this->numerator -= other.numerator * multiplierRight;
    this->denominator = sharedDenominator;
    this->simplify();

    return *this;
}

Rational& Rational::operator *= (const Rational& other) {
    this->numerator *= other.numerator;
    this->denominator *= other.denominator;
    this->simplify();

    return *this;
}

Rational& Rational::operator /= (const Rational& other) {
    this->operator *= (other.getReciprocal());
    this->simplify();

    return *this;
}

Rational& Rational::operator ++ () {
    this->operator += (Rational(1));
    return *this;
}

Rational& Rational::operator -- () {
    this->operator -= (Rational(1));
    return *this;
}

Rational Rational::operator ++ (int dummy) {
    Rational result = *this;
    this->operator += (Rational(1));
    return result;
}

Rational Rational::operator -- (int dummy) {
    Rational result = *this;
    this->operator -= (Rational(1));
    return result;
}

Rational Rational::operator - () const {
    return Rational(-this->numerator, this->denominator);
}

Rational operator + (const Rational& left, const Rational& right) {
    Rational result = left;
    result += right;
    return result;
}

bool operator == (const Rational& left, const Rational& right) {
    int lcm = LCM(left.getDenominator(), right.getDenominator());
    int multiplier1 = lcm / left.getDenominator();
    int multiplier2 = lcm / right.getDenominator();
    return left.getNumerator() * multiplier1 == right.getNumerator() * multiplier2;
}

bool operator != (const Rational& left, const Rational& right) {
    return !(left == right);
}

bool operator >= (const Rational& left, const Rational& right) {
    return (double)left >= (double)right;
}

bool operator <= (const Rational& left, const Rational& right) {
    return (double)left <= (double)right;
}

bool operator > (const Rational& left, const Rational& right) {
    return (double)left > (double)right;
}

bool operator < (const Rational& left, const Rational& right) {
    return (double)left < (double)right;
}

Rational operator - (const Rational& left, const Rational& right) {
    Rational result = left;
    result -= right;
    return result;
}

Rational operator * (const Rational& left, const Rational& right) {
    Rational result = left;
    result *= right;
    return result;
}

Rational operator / (const Rational& left, const Rational& right) {
    Rational result = left;
    result /= right;
    return result;
}

int Rational::getNumerator() const {
    return this->numerator;
}

int Rational::getDenominator() const {
    return this->denominator;
}

Rational Rational::getReciprocal() const {
    return Rational(this->denominator, this->numerator);
}

Rational::operator double() const {
    return (double)this->numerator / this->denominator;
}

Rational::operator bool() const {
    return this->numerator != 0;
}

std::ostream& operator << (std::ostream& os, const Rational& number) {
    if (number.getDenominator() == 1) {
        os << number.getNumerator();
    } else {
        os << number.getNumerator() << "/" << number.getDenominator();
    }
    return os;
}

std::istream& operator >> (std::istream& is, Rational& number) {
    char slash = 0;
    is >> number.numerator >> slash >> number.denominator;
    number.simplify();
    return is;
}