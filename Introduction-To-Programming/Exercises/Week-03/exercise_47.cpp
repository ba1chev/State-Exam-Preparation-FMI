// Въведете n и n на брой цифри. Изведете числото, което образуват.
#include <iostream>

int main() {
    int n = 0;
    int number = 0;
    std::cin >> n;

    int iter = 1;
    for (size_t i = 1; i < n; i++) {
        iter *= 10;
    }
    
    int current_number = 0;
    for (size_t i = 0; i < n; i++) {
        std::cin >> current_number;
        number += iter * current_number;
        iter /= 10;
    }
    
    std::cout << number << std::endl;
    return 0;
}