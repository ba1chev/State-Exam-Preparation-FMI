// Превърнете в двоична бройна система:
// 10(10); 132(10); 1010(10); AF1(16); 21(16); 17(8).
#include <iostream>

void to_bi_from_dec(int number) {
    bool buffer[1024];
    for (size_t i = 0; i < 1024; i++) {
        buffer[i] = false;
    }
    
    int current_index = 0;
    while (number != 0) {
        buffer[current_index] = number % 2;
        current_index += 1;
        number /= 2;
    } 

    for (size_t i = 0; i < current_index; i++) {
        std::cout << buffer[current_index - i - 1];
    }
    std::cout << std::endl;
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

int to_dec_from_hex(const char* number, int size) {
    if (!number || size < 0) {
        std::cout << "Invalid function params" << std::endl;
        return -1;
    }

    int result = 0;
    int iter = 1;
    for (int i = size - 1; i >= 0; i--) {
        if (number[i] >= '0' && number[i] <= '9') {
            result += ((int)number[i] - (int)'0') * iter;
        } else if (number[i] >= 'A' && number[i] <= 'F') {
            result += ((int)number[i] - (int)'A' + 10) * iter;
        } else {
            std::cout << "Invalid function params" << std::endl;
            return -1;
        }
        iter *= 16;
    }
    
    return result;
}

int main() {
    to_bi_from_dec(10);
    to_bi_from_dec(132);
    to_bi_from_dec(1010);
    to_bi_from_dec(to_dec_from_oct(17));
    to_bi_from_dec(to_dec_from_hex("AF1", 3));
    to_bi_from_dec(to_dec_from_hex("21", 2));

    return 0;
}