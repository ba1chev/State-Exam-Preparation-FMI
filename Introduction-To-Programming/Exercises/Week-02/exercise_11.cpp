// Да се състави програма, която по дадено реално число 
// x извежда стойността на sinx по следната формула (x е в радиани): 
// $$ \sin x \approx \frac{16x (\pi - x)}{5\pi^2 - 4x (\pi - x)} $$
#include <iostream>

int main() {
    const float pi = 3.14159265359f;
    float number = 0.0;
    std::cin >> number;

    std::cout << (16 * number * (pi - number)) / 
        (5 * pi * pi - 4 * number * (pi - number)) << std::endl;
    return 0;
}