// Да се състави програма, която прочита от 
// клавиатурата две цифри (като знаци от таблицата ASCII), 
// преобразува ги в числа и извежда тяхното произведение.
#include <iostream>

int main() {
    char left_number_char = '0';
    char right_number_char = '0';
    std::cin >> left_number_char >> right_number_char; 
    bool is_digit = (left_number_char >= '0' && left_number_char <= '9') &&
        (right_number_char >= '0' && right_number_char <= '9');

    if (!is_digit) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int left_number = (int)(left_number_char - '0');
    int right_number = (int)(right_number_char - '0');
    std::cout << left_number * right_number << std::endl;
    return 0;
}