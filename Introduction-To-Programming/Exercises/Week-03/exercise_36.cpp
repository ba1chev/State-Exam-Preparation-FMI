// Да се напише програма, която намира най-голямото 
// число измежду няколко числа, въведени от клавиатурата. 
// На първия ред от стандартния вход да се въведе броя на 
// числата, а на втория самите числа разделени с интервал. 
// На първия ред от стандартния изход да се изведе най-голямото число.
#include <iostream>

int main() {
    int numbers_count = 0;
    std::cin >> numbers_count;

    int current_number = 0;
    int max_number = INT_MIN;
    for (size_t i = 0; i < numbers_count; i++) {
        std::cin >> current_number;
        max_number = (
            max_number + current_number + std::abs(max_number - current_number)
        ) / 2;
    }
    
    std::cout << max_number << std::endl;
    return 0;
}