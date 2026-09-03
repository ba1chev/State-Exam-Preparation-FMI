// Да се изведат всички цели числа от m до n, които се делят на k.
#include <iostream>

int main() {
    int m, n, k = 0;
    std::cin >> m >> n >> k;
    if (m > n) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    for (int i = m; i <= n; i++) {
        if (i % k == 0) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}