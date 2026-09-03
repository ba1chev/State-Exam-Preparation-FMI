// Напишете програма, която приема цяло число n. 
// Да се изведат всички цели числа от n до 1, 
// всяко на различен ред.
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << std::endl;

    if (n >= 0) {
        for (int i = n; i >= 1; i--) {
            std::cout << i << std::endl;
        }
    } else {
        for (int i = n; i <= 1; i++) {
            std::cout << i << std::endl;
        }   
    }

    return 0;
}