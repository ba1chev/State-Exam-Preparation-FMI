// Напишете функция, askUser(const int from, const int to), която кара 
// потребителя да въвежда числа докато не въведе число, което да е в указания интервал, 
// а като резултат връща въпросното число.
#include <iostream>

int askUser(const int from, const int to) {
    int current_number = 0;
    while (true) {
        std::cout << "Enter number between " << from << " to " << to << std::endl;
        std::cin >> current_number;
        
        if (current_number >= from && current_number <= to) {
            break;
        }
    }
    return current_number;
}

int main() {
    std::cout << std::endl << askUser(1, 10) << std::endl;
    return 0;
}