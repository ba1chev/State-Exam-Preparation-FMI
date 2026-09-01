// Да с напише програма, която въвежда 
// положително число и изчислява най-малката 
// степен на двойката, която е по-голяма от въведеното число.
#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;
    int current_index = 31;

    while (current_index > 0) {
        if ((1 << current_index) & number) {
            break;
        }
        current_index -= 1;
    }

    std::cout << (1 << (current_index + 1)) << std::endl;
    return 0;
}
