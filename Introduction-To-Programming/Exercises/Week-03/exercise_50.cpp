// Напишете програма, която генерира и изписва по еднa 
// произволна цифра и изписва датата в UNIX формат всяка секунда. 
// Програмата да приключва работа, когато генерираната произволна 
// цифра е равна на последната цифра на изписаното време.
#include <iostream>

int main() {
    std::srand(std::time(nullptr));
    int left_bound = 0;
    int right_bound = 9;
    time_t current_time = 0;
    int difference = right_bound - left_bound + 1;
    
    while (true) {
        int random_generated_digit = std::rand() % difference + left_bound;
        std::time(&current_time);
        std::cout << "Random generated digit: " <<
            random_generated_digit << ", UNIX time: " <<
            current_time << std::endl;
        if (random_generated_digit == (current_time % 10)) {
            break;
        }
    }

    return 0;
}