// Да се състави програма, която въвежда от клавиатурата цяло 
// число N, което да е по-малко или равно на 27 и извежда на 
// екрана трицифрените естествени числа, сумата от цифрите на 
// които е равна на N.
#include <iostream>

int main() {
    int N = 0;
    std::cin >> N;
    if (N > 27 || N < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    for (size_t i = 100; i <= 999; i++) {
        int first_digit = i / 100;
        int second_digit = (i / 10) % 10;
        int third_digit = i % 10;
        int current_sum = first_digit + second_digit + third_digit;

        if (current_sum == N) {
            std::cout << i << std::endl;
        }
    }
    
    return 0;
}
