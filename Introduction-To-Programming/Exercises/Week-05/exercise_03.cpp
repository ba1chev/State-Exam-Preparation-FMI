// Да се напише функция min(int a, int b), 
// която връща по-малкото от двете числа a и b.
#include <iostream>

int min(int a, int b) {
    return (a + b - std::abs(a - b)) / 2;
}

int main() {
    std::cout << min(1, 100) << std::endl;;
    return 0;
}