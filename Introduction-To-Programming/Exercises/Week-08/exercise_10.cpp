// Дадени са две цели числа, записани като знакови низове. 
// Напишете програма, която определя кое от двете числа е по-голямо.
#include <iostream>

bool is_digit(const char ch) {
    return (int)ch >= (int)'0' && (int)ch <= (int)'9';
}

bool is_bigger(const char* left_number, const char* right_number) {
    if (!left_number || !right_number) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    const char* temp_ptr = left_number;
    while (*temp_ptr != '\0') {
        if (!is_digit(*temp_ptr)) {
            std::cout << "Invalid function input" << std::endl;
            return false;
        }
        temp_ptr += 1;
    }
    temp_ptr = right_number;
    while (*temp_ptr != '\0') {
        if (!is_digit(*temp_ptr)) {
            std::cout << "Invalid function input" << std::endl;
            return false;
        }
        temp_ptr += 1;
    }
    temp_ptr = nullptr;

    int size_1 = strlen(left_number);
    int size_2 = strlen(right_number);
    if (size_1 == size_2) {
        int iter = 1;
        for (size_t i = 1; i < size_1; i++) {
            iter *= 10;
        }
        
        int iter_copy = iter;
        int number_1 = 0;
        int number_2 = 0;
        while (*left_number != '\0') {
            number_1 += (iter * (int)(*left_number - (char)'0'));
            iter /= 10;
            left_number += 1;
        }
        iter = iter_copy;
        while (*right_number != '\0') {
            number_2 += (iter * (int)(*right_number - (char)'0'));
            iter /= 10;
            right_number += 1;
        }

        return number_1 >= number_2;
    } else {
        return size_1 >= size_2;
    }
}

int main() {
    std::cout << is_bigger("124", "123") << std::endl;
    std::cout << is_bigger("1230", "124") << std::endl;
    std::cout << is_bigger("9", "11") << std::endl;
    std::cout << is_bigger("670", "563") << std::endl;
    return 0;
}