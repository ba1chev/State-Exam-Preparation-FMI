// Напишете програма, която получава число от конзолата и 
// прави следните проверки върху него: проверка за цялост, 
// като ако числото е цяло прави проверка за четност, а ако 
// не е - за знака му. Накрая да се извежда текст за това.
#include <iostream>


int main() {
    float number = 0.0f;
    std::cin >> number;

    if (number == (int)number) {
        if ((int)number % 2 == 0) {
            std::cout << "Even integer" << std::endl;
        } else {
            std::cout << "Odd integer" << std::endl;
        }
    } else {
        if (number < 0) {
            std::cout << "Negative rational" << std::endl;
        } else {
            std::cout << "Positive rational" << std::endl;
        }
    }

    return 0;
}