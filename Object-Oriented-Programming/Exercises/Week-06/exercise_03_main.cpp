#include "exercise_03.h"

int main() {
    Polynomial poly(2);
    poly.setCoeffAtCurrentDegree(0, 1);
    poly.setCoeffAtCurrentDegree(1, 2);
    poly.setCoeffAtCurrentDegree(2, 3);
    std::cout << poly << std::endl; // 1+(2)*x^1+(3)*x^2

    std::cout << poly.getCoeffAtCurrentDegree(2) << std::endl; // 3
    std::cout << poly.evaluate(2) << std::endl; // 17

    Polynomial copy = poly;
    copy.setCoeffAtCurrentDegree(0, 100);
    std::cout << copy << std::endl; // 100+(2)*x^1+(3)*x^2
    std::cout << poly << std::endl; // 1+(2)*x^1+(3)*x^2 (unchanged)

    Polynomial constant = Polynomial::createConstant(5);
    std::cout << constant << std::endl; // 5
    std::cout << constant.evaluate(42) << std::endl; // 5

    return 0;
}