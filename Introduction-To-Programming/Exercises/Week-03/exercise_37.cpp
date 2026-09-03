// Да се напише програма, която пресмята n-тото 
// число на Фибоначи. n се въвежда от клавиатурата.
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;

    if (n == 0) {
        std::cout << 0 << std::endl;
        return 0;
    } else if (n == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }

    int fibonacci_previos_1 = 0;
    int fibonacci_previos_2 = 1;
    for (size_t i = 2; i <= n; i++) {
        int fibonacci_current = fibonacci_previos_1 + fibonacci_previos_2;
        fibonacci_previos_1 = fibonacci_previos_2;
        fibonacci_previos_2 = fibonacci_current;
    }
    
    std::cout << fibonacci_previos_2;
    return 0;
}