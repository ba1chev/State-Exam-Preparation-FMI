// Въведете число а. Изведете цифрите на четните му позиции. (отляво-надясно)
#include <iostream>

int main() {
    int number = 0;
    int digits[1024];
    int current_index = 0;
    std::cin >> number;

    if (number < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    while (number != 0) {
        int current_digit = number % 10;
        digits[current_index] = current_digit;
        number /= 10;
        current_index += 1;
    }

    for (int i = current_index - 1; i >= 0; i--) {
        if ((current_index - i) % 2 == 0) {
            std::cout << digits[i] << " ";
        }
    }
    
    std::cout << std::endl;
    return 0;
}