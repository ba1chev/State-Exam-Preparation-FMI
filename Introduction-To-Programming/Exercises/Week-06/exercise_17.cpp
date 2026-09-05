// Дадено е число N (с не повече от 12 цифри). 
// Да се провери дали цифрите му образуват палиндром.
#include <iostream>

void is_palindrome(int number) {
    if (number < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int copy_number = number;
    int digit_count = 0;
    while (copy_number != 0) {
        digit_count += 1;
        copy_number /= 10;
    }
    if (digit_count > 12) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int* digits = new int[digit_count] {};
    int current_index = 0;
    while (number != 0) {
        digits[current_index] = number % 10;
        number /= 10;
        current_index += 1;
    }
    
    for (int i = 0; i < digit_count / 2; i++) {
        if (digits[i] != digits[digit_count - i - 1]) {
            delete[] digits;
            digits = nullptr;
            std::cout << "No" << std::endl;
            return;
        }
    }
    
    delete[] digits;
    digits = nullptr;
    std::cout << "Yes" << std::endl;
}

int main() {
    is_palindrome(1987891);
    is_palindrome(1223);
    return 0;
}