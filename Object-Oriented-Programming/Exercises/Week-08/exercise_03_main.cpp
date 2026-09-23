#include "exercise_03.h"

int main() {
    Rational a(1, 2);
    Rational b(2, 4);

    std::cout << a + b << " " << a - b << " " << a * b << " " << a / b << std::endl;
    std::cout << -a << " " << (double)a << " " << (bool)Rational() << std::endl;
    std::cout << (a == b) << " " << (a < Rational(1)) << " " << (a >= b) << std::endl;

    Rational c(3, 1);
    std::cout << c++ << " " << c << " " << ++c << std::endl;

    return 0;
}
