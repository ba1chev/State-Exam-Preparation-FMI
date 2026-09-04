// Напишете функция trunc(const double num), 
// която извършва операцията truncate върху подаденото число num. 
// (Премахва всички числа след десетичната запетая)
#include <iostream>

int trunc1(const double num) {
    return (int)num;
}

int main() {
    std::cout << trunc1(3.144141) << std::endl;
    return 0;
}