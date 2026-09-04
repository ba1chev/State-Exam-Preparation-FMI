// Да се състави програма, която въвежда от клавиатурата 
// три цели числа m, n и k и извежда всички числа в интервала 
// [m,n] (0 < m < n <= 1000000), за които средното аритметично 
// от цифрите е по-голямо или равно на k (0 < k < 10).
#include <iostream>

float get_digits_avarage(int number) {
    float result = 0.0f;
    int counter = 0;
    while (number != 0) {
        result += (number % 10);
        number /= 10;
        counter += 1;
    }

    return result / counter;
}

void print_numbers_with_avg_digits(int m, int n, int k) {
    if (m < 0 || m >= n || n > 1000000 || k < 0 || k > 10) {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    for (size_t i = m; i <= n; i++) {
        if (get_digits_avarage(i) >= k) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    print_numbers_with_avg_digits(10, 50, 6);
    return 0;
}