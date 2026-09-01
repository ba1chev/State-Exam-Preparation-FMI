// Превърнете в шестнадесетична бройна система:
// 10(10); 132(10); 1010(10); 1101(2); 11010001(2); 1010101110(2); 71(8).
#include <iostream>

void to_hex_from_dec(int number) {
    char buffer[1024];

    int current_index = 0;
    while (number != 0) {
        int remaining = number % 16;
        if (remaining >= 10) {
            buffer[current_index] = (char)((int)'A' + remaining - 10);
        } else {
            buffer[current_index] = (char)((int)remaining + (int)'0');
        }

        current_index += 1;
        number /= 16;
    }

    for (size_t i = 0; i < current_index; i++) {
        std::cout << buffer[current_index - i - 1];
    }
    std::cout << std::endl;
}

int to_dec_from_bin(const char* number, int size) {
    if (!number || size < 0) {
        std::cout << "Invalid function params" << std::endl;
        return -1;
    }

    for (size_t i = 0; i < size; i++) {
        if (number[i] != '0' && number[i] != '1') {
            std::cout << "Invalid function params" << std::endl;
            return -1;
        }
    }

    int result = 0;
    for (int i = size - 1; i >= 0; i--) {
        bool is_upper = number[i] == '1';
        result += is_upper * (1 << (size - i - 1));
    }
    
    return result;
}

int to_dec_from_oct(int number) {
    int result = 0;

    int iter = 1;
    while (number != 0) {
        int current_digit = number % 10;
        result += iter * current_digit;
        iter *= 8;
        number /= 10;
    }

    return result;
}

int main() {
    to_hex_from_dec(10);
    to_hex_from_dec(132);
    to_hex_from_dec(1010);
    to_hex_from_dec(to_dec_from_bin("1101", 4));
    to_hex_from_dec(to_dec_from_bin("11010001", 8));
    to_hex_from_dec(to_dec_from_bin("1010101110", 10));
    to_hex_from_dec(to_dec_from_oct(71));

    return 0;
}