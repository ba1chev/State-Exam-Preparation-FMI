// Да се напише програма, която пресмята сумата:
// 1 + 2 + 3 + 4 + ... + 100;
// m + (m + 1) + (m + 2) + ... + (m + n);
// 1 + 1/2 + 1/3 + 1/4 + … + 1/10.
#include <iostream>

int main() {
    int sum1 = 0;
    int sum2 = 0;
    float sum3 = 0;
    int m, n = 0;
    std::cin >> m >> n;

    for (size_t i = 1; i <= 100; i++) {
        sum1 += i;
    }
    std::cout << "Sum1 is: " << sum1 << std::endl;

    for (size_t i = 0; i <= n; i++) {
        sum2 += m + i;
    }
    std::cout << "Sum2 is: " << sum2 << std::endl;

    for (size_t i = 1; i <= 10; i++) {
        sum3 += 1.0f / i;
    }
    std::cout << "Sum3 is: " << sum3 << std::endl;

    return 0;
}