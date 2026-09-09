// Напишете програма, която въвежда две числа и отпечатва 
// адресите на променливите, в които са съхранени.
#include <iostream>

int main() {
    int a, b = 0;
    std::cin >> a >> b;
    std::cout << &a << " " << &b << std::endl;
    return 0;
}