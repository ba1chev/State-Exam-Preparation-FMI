// Да се напише програма, която въвежда от 
// клавиатурата цялото число n > 0, след това въвежда още 
// n числа и отпечатва сумата им.
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;

    int current_number = 0;
    int numbers_sum = 0;
    for (size_t i = 0; i < n; i++) {
        std::cin >> current_number;
        numbers_sum += current_number;
    }
    
    std::cout << numbers_sum << std::endl;
    return 0;
}