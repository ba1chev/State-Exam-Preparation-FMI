// Като се използва рекурсивната дефиниция на функцията за степенуване да се 
// напише програма, която по дадени x реално и n – цяло число, намира 
// стойността на xn
#include <iostream>

float get_power(const float number, int degree) {
    if (degree == 1) {
        return number;
    } else if (degree == -1) {
        return (1 + 0.0f) / (number + 0.0f);
    } else if (degree > 0) {
        return number * get_power(number, degree - 1);
    } else if (degree < 0) {
        return (1 + 0.0f) / (number + 0.0f) * get_power(number, degree + 1);
    }
    return 0.0f;
} 

int main() {
    std::cout << get_power(5, 2) << std::endl;
    std::cout << get_power(-5, 3) << std::endl;
    std::cout << get_power(5, -2) << std::endl;
    std::cout << get_power(-5, -3) << std::endl;
    return 0;
}