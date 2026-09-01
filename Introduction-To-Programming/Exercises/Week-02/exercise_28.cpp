// Напишете програма, която въвежда десетично число 
// и го извежда на екрана в осмичен формат.
#include <iostream>

int main() {
    int number = 0;
    int octal_number[1024];
    int current_index = 0;
    std::cin >> number;

    if (number == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    while (number != 0) {
        int current_remaining = number % 8;
        octal_number[current_index] = current_remaining;
        current_index += 1;
        number /= 8;
    }

    for (size_t i = 0; i < current_index; i++) {
        std::cout << octal_number[current_index - i - 1];
    }
    
    std::cout << std::endl;
    return 0;
}
