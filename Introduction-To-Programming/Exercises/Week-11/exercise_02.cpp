// Редицата на Фибоначи 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, … се 
// дефинира по следния начин: първият елемент е 0, вторият е 1, а всеки 
// следващ се получава като сума от предходните два. Напишете рекурсивна 
// програма, която пресмята n-тия член на редицата на Фибоначи.
#include <iostream>

int generate_n_fibonacci(int number) {
    if (number <= 1) {
        return number;
    }

    return generate_n_fibonacci(number - 1)
        + generate_n_fibonacci(number - 2);
}

int main() {
    std::cout << generate_n_fibonacci(4) << std::endl;

    return 0;
}