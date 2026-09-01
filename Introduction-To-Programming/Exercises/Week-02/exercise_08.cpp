// Да се състави програма, която прочита реално число и извежда дали то е цяло.
#include <iostream>

int main() {
    float real_number = 0.0;
    std::cin >> real_number;
    std::cout << (((int)real_number - real_number) == 0) << std::endl;
    return 0;
}
