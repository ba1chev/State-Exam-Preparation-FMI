// Напишете програма, която въвежда 
// 3 числа a, b и c и ги извежда сортирани
#include <iostream>

int main() {
    int a, b, c = 0;
    std::cin >> a >> b >> c;

    if (a <= b && a <= c) {
        std::cout << a << " ";
        if (b <= c) {
            std::cout << b << " " << c << std::endl;
        } else {
            std::cout << c << " " << b << std::endl;
        }

    } else if (b <= a && b <= c) {
        std::cout << b << " ";
        if (a <= c) {
            std::cout << a << " " << c << std::endl;
        } else {
            std::cout << c << " " << a << std::endl;
        }
    } else if (c <= a && c <= b) {
        std::cout << c << " ";
        if (a <= b) {
            std::cout << a << " " << b << std::endl; 
        } else {
            std::cout << b << " " << a << std::endl;
        }
    }

    return 0;
}