// Да се състави програма, която по зададен интервал 
// [K,L] (K и L цели положителни числа не по-големи от 100000) 
// отпечатва всички числа в интервала [K,L], които имат две 
// съседни еднакви цифри в записа си.
#include <iostream>

bool has_to_equal_neighboring(int number) {
    int prev_digit = -1;
    int current_digit = -1;
    while (number != 0) {
        prev_digit = current_digit;
        current_digit = number % 10;
        if (current_digit == prev_digit) {
            return true;
        }
        number /= 10;
    }

    return false;
}

void print_special_numbers(int K, int L) {
    if (K > L || K > 100000 || L > 100000) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    for (int i = K; i <= L; i++) {
        if (has_to_equal_neighboring(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    print_special_numbers(60, 120);
    return 0;
}