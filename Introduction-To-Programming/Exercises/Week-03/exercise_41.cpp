// Изведете на екрана всички трицифрени числа, 
// сумата на цифрите на които е двуцифрено число.
#include <iostream>

int main() {
    for (size_t i = 100; i <= 999; i++) {
        int current_sum = 0;
        int current_number = i;
        while (current_number != 0) {
            current_sum += current_number % 10;
            current_number /= 10;
        }

        if (current_sum >= 10 && current_sum <= 99) {
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}