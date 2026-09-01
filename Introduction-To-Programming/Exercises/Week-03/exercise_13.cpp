// Напишете програма, която приема 
// две числа от конзолата и изписва 
// по-голямото от тях.
#include <iostream>

int main() {
    int a, b = 0;
    std::cin >> a >> b;

    if (a >= b) {
        std::cout << a << std::endl;
    } else {
        std::cout << b << std::endl;
    }

    return 0;
}
