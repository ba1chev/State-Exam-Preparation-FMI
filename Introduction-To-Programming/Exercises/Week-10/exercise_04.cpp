// Въведено е число a. Да се изведе неговия двоичен запис.
#include <iostream>

int get_needed_digits(int number) {
    int counter = 0;
    while (number != 0) {
        number /= 2;
        counter += 1;
    }

    return counter;
}

const char* to_binary(int number) {
    int size = get_needed_digits(number);
    char* result = new char[size + 1]{};
    for (int i = size - 1; i >= 0; i--) {
        int current_remainder = number % 2;
        result[i] = current_remainder + '0';
        number /= 2;
    }

    result[size] = '\0';
    return result;
}

int main() {
    const char* binary = to_binary(123);
    std::cout << binary << std::endl;

    delete[] binary;
    binary = nullptr;
    return 0;
}