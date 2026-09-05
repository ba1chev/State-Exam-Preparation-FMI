// Да се дефинира функция sortLex, която получава като аргументи 
// положителното число n и масив a, съдържащ n на брой цели неотрицателни
// числа, и ги сортира във възходящ ред относно лексикографската наредба 
// (например, 123 е преди 9 по лексикографската наредба).
#include <iostream>

int get_count_of_digits(int number) {
    int counter = 0;
    while (number != 0) {
        counter += 1;
        number /= 10;
    }

    return counter;
}

char* to_str(int number) {
    int size = get_count_of_digits(number);
    if (!size) {
        char* result = new char[2] {};
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    char* result = new char[size + 1] {};
    result[0] = '0';
    for (size_t i = 0; i < size; i++) {
        result[i] = (char)((int)(number % 10) + (int)'0');
        number /= 10;
    }
    
    for (size_t i = 0; i < size / 2; i++) {
        char temp = result[i];
        result[i] = result[size - i - 1];
        result[size - i - 1] = temp;
    }
    
    result[size] = '\0';
    return result;
}

bool string_compare(const char* str_1, const char* str_2) {
    while (*str_1 != '\0' && *str_2 != '\0' && (int)*str_1 == (int)*str_2) {
        str_1 += 1;
        str_2 += 1;
    }
    return (int)*str_1 > (int)*str_2;
}

void bubble_sort(char** array, int size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (string_compare(array[j], array[j + 1])) {
                char* temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void sortLex(const int size, const int* array) {
    if (!array || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    char** num_strings = new char* [size] {nullptr};
    for (size_t i = 0; i < size; i++) {
        num_strings[i] = to_str(array[i]);
    }
    bubble_sort(num_strings, size);

    for (size_t i = 0; i < size; i++) {
        std::cout << num_strings[i] << " ";
        delete[] num_strings[i];
        num_strings[i] = nullptr;
    }
    std::cout << std::endl;
    delete[] num_strings;
    num_strings = nullptr;
}

int main() {
    int array[6] = {13, 14, 7, 2018, 9, 0};
    sortLex(6, array);
    return 0;
}