// Да се дефинира рекурсивна функция, която изчислява 
// биномния коефициент
#include <iostream>

int comb(int m, int n) {
    if (n == 0 || m == n) {
        return 1;
    }

    return comb(m - 1, n - 1) + comb(m - 1, n);
}

int main() {
    std::cout << comb(4, 1) << std::endl;
    std::cout << comb(10, 2) << std::endl;
    return 0;
}