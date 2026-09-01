// Да се състави програма, която прочита 
// реално число и извежда дали то е точен квадрат.
#include <iostream>

int main() {
    float real_number = 0.0;
    std::cin >> real_number;
    int number = (int)real_number;
    if (real_number != (int)real_number) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }
    
    int current_number = 0;
    while (true) {
        int multiplication = current_number * current_number;
        if (multiplication > number) {
            std::cout << false << std::endl;
            break;
        }
        else if ((current_number * current_number) == number) {
            std::cout << true << std::endl;
            break;
        }
        current_number += 1;
    }

    return 0;
}