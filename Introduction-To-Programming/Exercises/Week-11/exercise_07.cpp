// Да се напише рекурсивна функция, която отпечатва в 
// обратен ред цифрите на дадено цяло положително число.
#include <iostream>

void print_reversed_digits(int number) {
    if (!number) {
        std::cout << std::endl;
        return;
    }
    std::cout << number % 10;
    print_reversed_digits(number / 10);
}

int main() {
    print_reversed_digits(123);
    return 0;
}