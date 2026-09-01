// Напишете програма, която проверява има 
// ли сред цифрите на дадено положително трицифрено 
// число две равни.
#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;

    int digits[10];
    for (size_t i = 0; i < 10; i++) {
        digits[i] = 0;
    }

    while (number != 0) {
        int current_digit = number % 10;
        digits[current_digit] += 1;
        number /= 10;
    }

    for (size_t i = 0; i < 10; i++) {
        if (digits[i] > 1) {
            std::cout << true << std::endl;
            return 0;
        }
    }
    
    std::cout << false << std::endl;
    return 0;
}