#include "exercise_03.h"

int main() {
    Polynomial poly(2);
    poly.setCoeffAtCurrentDegree(0, 1);
    poly.setCoeffAtCurrentDegree(1, 2);
    poly.setCoeffAtCurrentDegree(2, 3);
    std::cout << poly << std::endl;

    std::cout << poly.getCoeffAtCurrentDegree(2) << std::endl;
    std::cout << poly.evaluate(2) << std::endl;

    Polynomial copy = poly;
    copy.setCoeffAtCurrentDegree(0, 100);
    std::cout << copy << std::endl;
    std::cout << poly << std::endl;

    Polynomial constant = Polynomial::createConstant(5);
    std::cout << constant << std::endl;
    std::cout << constant.evaluate(42) << std::endl;

    return 0;
}