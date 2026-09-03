// Напишете програма, която по въведено цяло 
// положително число n извежда дали е просто.
#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;
    if (number < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    bool is_prime = number >= 2;
    for (size_t i = 2; i < number; i++) {
        is_prime = !(number % i == 0);
        if (!is_prime) {
            break;
        }
    }
    
    if (is_prime) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    return 0;
}