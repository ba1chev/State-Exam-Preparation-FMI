// Да се дефинира функция sortLex, която получава като 
// аргументи положителното число n и масив a, съдържащ n на брой цели 
// неотрицателни числа, и ги сортира във възходящ ред относно лексикографската 
// наредба (например, 123 е преди 9 по лексикографската наредба).
#include <iostream>

int get_digits_count(int number) {
    if (!number) {
        return 1;
    }

    int counter = 0;
    while (number != 0) {
        number /= 10;
        counter += 1;
    }

    return counter;
}

bool compare_numeric_strings(const char* left, const char* right) {
    if (!left || !right) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    while (*left == *right) {
        left += 1;
        right += 1;
    }

    return (int)*left >= (int)*right;
}

void bubble_sort(char** array, int size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (compare_numeric_strings(array[j], array[j + 1])) {
                char* temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void sortLex(const unsigned int* array, int size) {
    if (!array || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    char** strings = new char*[size]{nullptr};
    for (size_t i = 0; i < size; i++) {
        int current_number = array[i];
        int current_size = get_digits_count(current_number);
        strings[i] = new char[current_size + 1]{};

        if (current_number) {
            int j = 0;
            while (current_number != 0) {
                int current_digit = current_number % 10;
                strings[i][j] = (char)((int)current_digit + (int)'0');
                j += 1;
                current_number /= 10;
            }
        } else {
            strings[i][0] = '0';
        }
        strings[i][current_size] = '\0';

        for (size_t k = 0; k < current_size / 2; k++) {
            char temp = strings[i][k];
            strings[i][k] = strings[i][current_size - k - 1];
            strings[i][current_size - k - 1] = temp;
        }
    }

    bubble_sort(strings, size);
    for (size_t i = 0; i < size; i++) {
        std::cout << strings[i] << " ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < size; i++) {
        delete[] strings[i];
        strings[i] = nullptr;
    }
    delete[] strings;
    strings = nullptr;
}

int main() {
    unsigned int array[6] = {13, 14, 7, 2018, 9, 0};
    sortLex(array, 6);
    return 0;
}