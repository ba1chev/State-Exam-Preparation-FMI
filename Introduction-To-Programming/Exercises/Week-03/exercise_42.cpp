// Въведете число a. Изведете всичките му делители.
#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;

    for (size_t i = 1; i <= number; i++) {
        if (number % i == 0) {
            std::cout << i << " ";
        }
    }
    
    std::cout << std::endl;
    return 0;
}
