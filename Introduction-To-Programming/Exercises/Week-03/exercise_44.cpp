// Напишете програма, която приема цели числа и приключва работа, 
// когато се въведат 5 положителни числа. 
// Накрая да се изведе сумата от всички въведени числа.
#include <iostream>

int main() {    
    int sum = 0;
    int counter = 0;
    int current_number = 0;
    while (true) {
        if (counter == 5) {
            break;
        }

        std::cin >> current_number;
        sum += current_number;
        if (current_number > 0) {
            counter += 1;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}