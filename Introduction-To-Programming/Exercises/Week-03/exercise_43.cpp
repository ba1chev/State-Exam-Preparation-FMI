// Програмистите имат един интересен навик - когато нещо се развали, 
// си създават ново. Затова и студентите от КН решиха да си напишат 
// собствен калкулатор, вместо да правят нещо толкова тривиално като 
// закупуването му от книжарница. Калкулаторът смята прости изрази от 
// вида “<число> <операция> <число> <операция>...”, където <операция> 
// може да бъде +, -, *, /, а <число> е реално число. Въвеждането 
// продължава до въведен знак =, а действията се изпълняват без 
// приоритет по реда на въвеждане.
#include <iostream>

int main() {
    float result = 0;
    float current_number = 0;
    std::cin >> result;

    while (true) {
        char current_operation = '=';
        std::cin >> current_operation;

        switch (current_operation) {
            case '+': {
                std::cin >> current_number;
                result += current_number;
                break;
            }
            case '-': {
                std::cin >> current_number;
                result -= current_number;
                break;
            }
            case '*': {
                std::cin >> current_number;
                result *= current_number;
                break;
            }
            case '/': {
                std::cin >> current_number;
                if (current_number == 0) {
                    std::cout << "Zero division" << std::endl;
                    return 1;
                }
                result /= current_number;
                break;
            }
            case '=': {
                std::cout << result << std::endl;
                return 0;
            }
            default: {
                std::cout << "Invalid input operation" << std::endl;
                return 1;
            }
        }
    }

    return 1;
}