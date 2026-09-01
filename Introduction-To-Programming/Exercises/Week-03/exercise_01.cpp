// Задача Кубично уравнение от вида x3+px+q=0, 
// където 4p^3+27q^2>0, има един реален корен, 
// който може да се намери с формулата на Кардано. 
// Да се напише програма, която въвежда p и q и изчислява този корен.
#include <iostream>
#include <cmath>

int main() {
    int p, q = 0;
    std::cin >> p >> q;
    float left_part = std::cbrt(
        (-q / 2.0f) + std::sqrt(
            (q * q) / 4.0f + (p * p * p) / 27.0f
        )
    );
    float right_part = std::cbrt(
        (-q / 2.0f) - std::sqrt(
            (q * q) / 4.0f + (p * p * p) / 27.0f
        )
    );

    std::cout << left_part + right_part << std::endl;
    return 0;
}