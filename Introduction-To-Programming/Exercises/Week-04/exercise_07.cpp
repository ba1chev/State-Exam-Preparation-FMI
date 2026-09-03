// Да се състави програма, която въвежда от клавиатурата цяло число 
// N и намира всички трицифрени числа по-малки от N, които не съдържат 
// еднакви цифри.
#include <iostream>

int main() {
    int N = 0;
    std::cin >> N;
    if (N < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << std::endl;
    int upper_bound = N < 999 ? N - 1 : 999;
    for (size_t i = 100; i <= upper_bound; i++) {
        int first_digit = i / 100;
        int second_digit = (i / 10) % 10;
        int third_digit = i % 10;

        if ((first_digit ^ second_digit) != 0 &&
            (first_digit ^ third_digit) != 0 &&
            (second_digit ^ third_digit) != 0) {
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}