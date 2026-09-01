// Да се състави програма, която прочита от клавиатурата два реда по три цифри 
// (като знаци от таблицата ASCII), преобразува ги като числа и отпечатва тяхната сума.
#include <iostream>

int main() {
    char first_1 = 'a';
    char first_2 = 'a';
    char first_3 = 'a';
    std::cin >> first_1 >> first_2 >> first_3;
    bool is_digit_1 = (first_1 >= '0' && first_1 <= '9') &&
        (first_2 >= '0' && first_2 <= '9') && (first_3 >= '0' && first_3 <= '9');
    if (!is_digit_1) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    char second_1 = 'a';
    char second_2 = 'a';
    char second_3 = 'a';
    std::cin >> second_1 >> second_2 >> second_3;
    bool is_digit_2 = (second_1 >= '0' && second_1 <= '9') &&
        (second_2 >= '0' && second_2 <= '9') && (second_3 >= '0' && second_3 <= '9');
    if (!is_digit_2) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int left_number =
        100 * (int)(first_1 - '0') +
        10 * (int)(first_2 - '0') +
        1 * (int)(first_3 - '0')
    ;
    int right_number =
        100 * (int)(second_1 - '0') +
        10 * (int)(second_2 - '0') +
        1 * (int)(second_3 - '0')
    ;
    
    std::cout << left_number + right_number << std::endl;
    return 0;
}