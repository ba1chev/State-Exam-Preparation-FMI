// Огледално на дадено число наричаме това, съставено от 
// цифрите му в обратен ред. Да се въведе 
// четирицифрено число и да се изведе огледалното му.
#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;

    if (number < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    while (number != 0) {
        int current_digit = number % 10;
        std::cout << current_digit;
        number = number / 10;
    }

    std::cout << std::endl;
    return 0;
}