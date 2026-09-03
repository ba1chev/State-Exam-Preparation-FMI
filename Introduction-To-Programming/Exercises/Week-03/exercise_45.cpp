// Напишете програма, която приема цели числа и приключва работа, 
// когато се въведат последователно 3 положителни числа. 
// Накрая да се изведе произведението на въведените числа.
#include <iostream>

int main() {    
    int product = 1;
    int current_number = 0;

    while (true) {
        std::cin >> current_number;
        product *= current_number;

        if (current_number > 0) {
            bool pred = true;
            
            for (size_t i = 0; i < 2; i++) {
                std::cin >> current_number;
                product *= current_number;
                if (current_number <= 0) {
                    pred = false;
                    break;
                }
            }
            
            if (pred) {
                break;
            }
        }
    }

    std::cout << product << std::endl;
    return 0;
}