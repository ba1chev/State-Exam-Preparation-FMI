// Напишете програма, която въвежда три 
// реални числа, намира и извежда най-голямото от тях.
#include <iostream>

int main() {
    int a, b, c = 0;
    std::cin >> a >> b >> c;

    if (a >= b && a >= c) {
        std::cout << a << std::endl;
    } else if (b >= a && b >= c) {
        std::cout << b << std::endl;
    } else if (c >= a && c >= b) {
        std::cout << c << std::endl;
    }

    return 0;
}
