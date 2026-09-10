// Да се напише рекурсивна програма, която пресмята сумата на първите n естествени числа.
#include <iostream>

int calculate_first_numbers(const int number) {
    if (number == 0) {
        return 0;
    } else {
        return number + calculate_first_numbers(number - 1);
    }
}

int main() {
    std::cout << calculate_first_numbers(100) << std::endl; 
    return 0;
}