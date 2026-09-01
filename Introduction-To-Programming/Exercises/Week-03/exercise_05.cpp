// Да се напише програма, която извежда случайна 
// буква (малка или главна) от латинската азбука.
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    int lower_bound_1 = (int)'a';
    int upper_bound_1 = (int)'z';
    int lower_bound_2 = (int)'A';
    int upper_bound_2 = (int)'Z';
    int random_ascii_1 = rand() % 
        (upper_bound_1 - lower_bound_1 + 1) + lower_bound_1;
    int random_ascii_2 = rand() % 
        (upper_bound_2 - lower_bound_2 + 1) + lower_bound_2;

    int left_bound = 0;
    int right_bound = 1;
    bool choice = rand() % 
        (right_bound - left_bound + 1) + left_bound;
    if (choice) {
        std::cout << (char)random_ascii_1 << std::endl;
    } else {
        std::cout << (char)random_ascii_2 << std::endl;
    }

    return 0;
}
