// Да се въведат две числа - а и b, различни от 0. 
// Да се разменят стойностите им 
// (по три начина, без да се използва функцията swap).
#include <iostream>

int main() {
    int a, b = 0;
    std::cin >> a >> b;

    a ^= b;
    b ^= a;
    a ^= b;
    std::cout << a << " " << b << std::endl;
    return 0;
}