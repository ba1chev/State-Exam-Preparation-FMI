// Дадено е число N. Да се провери дали цифрите му образуват палиндром.
#include <iostream>

int get_number_digits_count(int number) {
    int counter = 0;
    while (number != 0) {
        counter += 1;
        number /= 10;
    }

    return counter;
}

bool is_palindrome(int number) {
    int size = get_number_digits_count(number);
    int* digits = new int[size]{};
    int current_index = 0;

    while (number != 0) {
        digits[current_index] = number % 10;
        current_index += 1;
        number /= 10;
    }

    for (size_t i = 0; i < size / 2; i++) {
        if (digits[i] != digits[size - i - 1]) {
            delete[] digits;
            digits = nullptr;
            return false;
        }
    }
    
    delete[] digits;
    digits = nullptr;
    return true;
}

int main() {
    int N = 0;
    std::cin >> N;
    if (N < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << is_palindrome(N) << std::endl;
    return 0;
}