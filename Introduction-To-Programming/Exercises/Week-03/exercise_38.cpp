// Въведете число а. Изведете цифрите му в обратен ред.
#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;

    while (number != 0) {
        int current_digit = number % 10;
        std::cout << current_digit;
        number /= 10;
    }

    std::cout << std::endl;
    return 0;
}