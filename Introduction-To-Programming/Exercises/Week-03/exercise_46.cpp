// Напишете програма, която приема цели числа и 
// приключва работа, когато се въведат последователно 
// 3 отрицателни числа. Накрая да се изведе най-малкото от тях.
#include <iostream>

int main() {    
    int min_number = 0;
    int current_number = 0;

    while (true) {
        std::cin >> current_number;

        if (current_number < 0) {
            bool pred = true;
            int current_min_number = current_number;
            
            for (size_t i = 0; i < 2; i++) {
                std::cin >> current_number;
                if (current_number >= 0) {
                    pred = false;
                    break;
                }
                current_min_number = (
                    current_min_number + current_number - 
                    std::abs(current_min_number - current_number)
                ) / 2;
            }
            
            if (pred) {
                min_number = current_min_number;
                break;
            }
        }
    }

    std::cout << min_number << std::endl;
    return 0;
}