// Задача Да се състави програма, която по дадено реално число 
// x извежда стойността на cosx по следната формула 
// (x е в радиани): $$ \cos x \approx \frac{\pi^2 - 4 x^2}{\pi^2 + x^2} $$
#include <iostream>

int main() {
    const float pi = 3.14159265359f;
    float number = 0.0;
    std::cin >> number;

    std::cout << (pi * pi - 4 * number * number) / 
        (pi * pi + number * number) << std::endl;
    return 0;
}