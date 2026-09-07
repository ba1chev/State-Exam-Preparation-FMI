// Напишете програма, която въвежда цяло число и извежда 
// двоичния (шeстнадесетичният) му запис.
#include <iostream>

void reverse(char* str, int size) {
    for (size_t i = 0; i < size / 2; i++) {
        char temp = str[i];
        str[i] = str[size - i - 1];
        str[size - i - 1] = temp;
    }
}

void print_binary(int number) {
    if (number < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    char buffer[1024]{};
    int current_index = 0;
    while (number != 0) {
        buffer[current_index] = (char)((int)(number % 2) + (int)'0');
        current_index += 1;
        number /= 2;
    }
    buffer[current_index] = '\0';
    reverse(buffer, current_index);
    std::cout << buffer << std::endl;
}

void print_hex(int number) {
    if (number < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }
    
    char buffer[1024]{};
    int current_index = 0;
    while (number != 0) {
        int remainder = number % 16;
        if (remainder < 10) {
            buffer[current_index] = (char)((int)remainder + (int)'0');
        } else {
            buffer[current_index] = (char)((int)remainder - 10 + (int)'A');
        }
        current_index += 1;
        number /= 16;
    }
    buffer[current_index] = '\0';
    reverse(buffer, current_index);
    std::cout << buffer << std::endl;
}

int main() {
    print_binary(128);
    print_binary(10);
    print_hex(128);
    print_hex(10);
    return 0;
}