// Напишете програма, която въвежда десетично число 
// и го извежда на екрана в шестнайсетичен формат.
#include <iostream>

int main() {
    int number = 0;
    char hex_number[1024];
    int current_index = 0;
    std::cin >> number;

    if (number == 0) {
        std::cout << "0" << std::endl;
        return 0;
    }

    while (number != 0) {
        int remaining = number % 16;
        if (remaining > 9) {
            hex_number[current_index] = (char)((int)'A' + remaining - 10);
        } else {
            hex_number[current_index] = (char)((int)'0' + remaining);
        }
        current_index += 1;
        number /= 16;
    }

    hex_number[current_index] = '\0';
    for (size_t i = 0; i < current_index / 2; i++) {
        char temp = hex_number[i];
        hex_number[i] = hex_number[current_index - i - 1];
        hex_number[current_index - i - 1] = temp;
    }
    
    std::cout << hex_number << std::endl;
    std::cout << std::endl;
    return 0;
}

