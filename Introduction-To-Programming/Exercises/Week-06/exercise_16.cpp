// Въведено е число a. Да се изведе неговия двоичен запис.
// Ограничения: Двоичният запис на числото няма да съдържа повече от 20 знака
#include <iostream>

void print_binary(int number) {
    if (!number) {
        std::cout << 0;
    }
    else if (number < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int current_index = 0;
    bool remainders[20] {false};
    while (number != 0) {
        if (current_index == 19) {
            break;
        }
        remainders[current_index] = number % 2;
        current_index += 1;
        number /= 2;
    }

    for (int i = current_index - 1; i >= 0; i--) {
        std::cout << remainders[i];
    }
    std::cout << std::endl;
}

int main() {
    print_binary(123);
    return 0;
}