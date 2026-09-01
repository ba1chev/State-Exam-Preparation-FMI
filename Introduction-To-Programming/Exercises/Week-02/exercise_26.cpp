// Напишете програма, която въвежда 3 числа 
// a, b и x и съответно извежда:
#include <iostream>

int main() {
    int a, b, x = 0;
    std::cin >> a >> b >> x;

    if (x < a) {
        std::cout << 1 << std::endl;
    } else if (x == a) {
        std::cout << 2 << std::endl;
    } else if (x > a && x < b) {
        std::cout << 3 << std::endl;
    } else if (x == b) {
        std::cout << 4 << std::endl;
    } else if (x > b) {
        std::cout << 5 << std::endl;
    }

    return 0;
}
