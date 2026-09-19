#include "exercise_03.h"

void Polynomial::free() {
    delete[] this->coefficents;
    this->coefficents = nullptr;
    this->degree = 0;
}
    
void Polynomial::resize(const size_t newDegree) {
    if (this->degree >= newDegree) {
        throw std::runtime_error("New capacity must be greater");
    }

    float* newCoefficent = new float[newDegree + 1]{};
    for (size_t i = 0; i <= this->degree; i++) {
        newCoefficent[i] = this->coefficents[i];
    }

    delete[] this->coefficents;
    this->coefficents = newCoefficent;
    this->degree = newDegree;
}

void Polynomial::copyFrom(const Polynomial& other) {
    this->coefficents = new float[other.degree + 1]{};
    this->degree = other.degree;
    for (size_t i = 0; i <= this->degree; i++) {
        this->coefficents[i] = other.coefficents[i];
    }
}
    
void Polynomial::moveTo(Polynomial&& other) noexcept {
    this->coefficents = other.coefficents;
    this->degree = other.degree;

    other.coefficents = nullptr;
    other.degree = 0;
}

Polynomial::Polynomial() {
    this->degree = 0;
    this->coefficents = new float[this->degree + 1]{};
}

Polynomial::Polynomial(const size_t degree) {
    this->degree = degree;
    this->coefficents = new float[this->degree + 1]{};
}

Polynomial::Polynomial(const Polynomial& other) {
    this->copyFrom(other);
}

Polynomial::Polynomial(Polynomial&& other) noexcept {
    this->moveTo(std::move(other));
}

Polynomial& Polynomial::operator = (const Polynomial& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

Polynomial& Polynomial::operator = (Polynomial&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

Polynomial::~Polynomial() {
    this->free();
}

void Polynomial::setCoeffAtCurrentDegree(const size_t targetDegree, const float coeff) {
    if (targetDegree > this->degree) {
        throw std::out_of_range("Target degree is out of range");
    }
    this->coefficents[targetDegree] = coeff;
}

float Polynomial::getCoeffAtCurrentDegree(const size_t targetDegree) const {
    if (targetDegree > this->degree) {
        throw std::out_of_range("Target degree is out of range");
    }
    return this->coefficents[targetDegree];
}

float Polynomial::evaluate(const float x) const {
    float result = 0.0f;
    float currentPowerOfX = 1.0f;
    for (size_t i = 0; i <= this->degree; i++) {
        result += this->coefficents[i] * currentPowerOfX;
        currentPowerOfX *= x;
    }

    return result;
}

Polynomial Polynomial::createConstant(const double value) {
    Polynomial result(0);
    result.setCoeffAtCurrentDegree(0, value);
    return result;
}

std::ostream& operator << (std::ostream& os, const Polynomial& poly) {
    for (size_t i = 0; i <= poly.degree; i++) {
        if (i == 0) {
            os << poly.coefficents[i];
        } else {
            os << "+(" << poly.coefficents[i] << ")*x^" << i;
        }
    }

    return os;
}
