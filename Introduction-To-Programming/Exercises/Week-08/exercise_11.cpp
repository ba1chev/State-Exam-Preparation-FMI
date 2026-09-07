// Да се напише програма, която сортира във възходящ ред 
// елементите на редица от числа във формата на низове.
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

        return number_1 > number_2;
    } else {
        return size_1 > size_2;
    }
}

void bubble_sort(const char** array, int size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (is_bigger(array[j], array[j + 1])) {
                const char* temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() {
    const char* numbers[5] = {"15", "3", "27", "8", "1"};
    bubble_sort(numbers, 5);

    for (size_t i = 0; i < 5; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}