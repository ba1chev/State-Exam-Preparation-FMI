// Напишете програма, която въвежда 
// две числа - a и b и връща (a + b)3
#include <iostream>

int main() {
    float a, b = 0.0;
    std::cin >> a >> b;
    float sum = a + b;
    std::cout << sum * sum * sum << std::endl;
    return 0;
}