// Да се изведат всички цели числа от 5 до 100, 
// които се делят на 5.
#include <iostream>

int main() {
    for (size_t i = 5; i <= 100; i++) {
        if (i % 5 == 0) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}