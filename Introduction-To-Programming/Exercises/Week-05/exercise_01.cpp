// Да се състави функция sum(const int a, const int b), 
// която приема две числа и връща като резултат сбора им.
#include <iostream>

int sum(const int a, const int b) {
    return a + b;
}

int main() {
    std::cout << sum(1, 2) << std::endl;
    return 0;
}