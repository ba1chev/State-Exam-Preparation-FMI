// Реализирайте система за изчисления на полиноми със структурата Polynomial 
// със следните член-данни:
// коефициентите (най-много 20)
// степента на полинома (Коефициентът на x^i се пази на позиция i в масива.)
// Реализирайте следните функции:
// Създава полином по подадени коефициенти и степен.
// Пресмята стойността на полином в точка x.
// Събира два полинома.
// Изважда два полинома.
// Умножава два полинома.
// Извежда полином на стандартния изход (например 3.00x^2 + 2.00x^1 + 1.00x^0).
#include <iostream>
#include <algorithm>

struct Polynomial {
public:
    float coefficents[21]{};
    int degree = 0;

    Polynomial() {
        for (size_t i = 0; i < 20; i++) {
            this->coefficents[i] = 0.0f;
        }
        this->degree = 0;
    }

    Polynomial(const float* coefficents, int degree) {
        if (!coefficents || degree < 0 || degree > 20) {
            throw std::runtime_error("Invalid input");
        }

        for (size_t i = 0; i < degree; i++) {
            this->coefficents[i] = coefficents[i];
        }
        this->degree = degree;
    } 
};

float calculateAt(const Polynomial& poly, int x) {
    float result = 0.0f;
    for (size_t i = 0; i < poly.degree; i++) {
        float poweredX = 1.0f;
        for (size_t j = 0; j < i; j++) {
            poweredX *= x;
        }

        result += poly.coefficents[i] * poweredX;
    }

    return result;
}

Polynomial addTwo(const Polynomial& left, const Polynomial& right) {
    Polynomial result;
    result.degree = std::max(left.degree, right.degree);

    for (size_t i = 0; i < 21; i++) {
        result.coefficents[i] = left.coefficents[i] + right.coefficents[i];
    }
    return result;
}

Polynomial subtractTwo(const Polynomial& left, const Polynomial& right) {
    Polynomial negativePoly = right;
    for (size_t i = 0; i < 21; i++) {
        negativePoly.coefficents[i] *= -1;
    }
    return addTwo(left, negativePoly);
}

Polynomial multTwo(const Polynomial& left, const Polynomial& right) {
    if (left.degree + right.degree > 20) {
        throw std::runtime_error("Invalid input");
    }

    Polynomial result;
    for (size_t i = 0; i < left.degree; i++) {
        for (size_t j = 0; j < right.degree; j++) {
            result.coefficents[i + j] += left.coefficents[i] *
                right.coefficents[j];
        }
    }
    result.degree = left.degree + right.degree - 1;

    return result;
}

void printPolynomial(const Polynomial& poly) {
    int lastNonZeroIndex = 0;
    for (size_t i = 0; i < 21; i++) {
        if (poly.coefficents[i] != 0) {
            lastNonZeroIndex = i;
        }
    }
    
    for (size_t i = 0; i < 21; i++) {
        if (i != lastNonZeroIndex && poly.coefficents[i] != 0) {
            std::cout << poly.coefficents[i] << "*x^" << i << " + ";
        }  else if (i == lastNonZeroIndex && poly.coefficents[i] != 0) {
            std::cout << poly.coefficents[i] << "*x^" << i;
        }
    }
    std::cout << std::endl;
}

int main() {
    float leftCoeffs[] = {1.0f, 2.0f, 3.0f};
    Polynomial left(leftCoeffs, 3);

    float rightCoeffs[] = {5.0f, 1.0f};
    Polynomial right(rightCoeffs, 2);

    std::cout << "Left: ";
    printPolynomial(left);
    std::cout << "Right: ";
    printPolynomial(right);

    std::cout << "Left at x=2: " << calculateAt(left, 2) << std::endl;

    std::cout << "Sum: ";
    printPolynomial(addTwo(left, right));
    std::cout << "Difference: ";
    printPolynomial(subtractTwo(left, right));
    std::cout << "Product: ";
    printPolynomial(multTwo(left, right));

    return 0;
}