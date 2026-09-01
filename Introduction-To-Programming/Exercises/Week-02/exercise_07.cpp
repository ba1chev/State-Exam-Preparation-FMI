// Задача Да се състави програма, която прочита две реални числа: 
// C - температура в градуси Целзий (°C) и F - температура в градуси Фаренхайт 
// (°F). Да се изведе дали двете температури са еднакви
#include <iostream>
#include <cmath>

int main() {
    float C = 0.0;
    float F = 0.0;
    const float tolerance = 0.001;
    std::cin >> C >> F;

    std::cout << (std::abs((F - 32) * (5.0f / 9.0f) - C) < tolerance) << std::endl;
    return 0;
}