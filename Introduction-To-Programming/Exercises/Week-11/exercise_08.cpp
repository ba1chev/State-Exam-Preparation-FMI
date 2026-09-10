// Съставете рекурсивна подпрограма, която намира 
// сумата от цифрите на дадено цяло положително число.
#include <iostream>

int sum_of_digits(int number) {
    if (!number) {
        return 0;
    }
    return number % 10 + sum_of_digits(number / 10);
}

int main() {
    std::cout << sum_of_digits(123) << std::endl;
    return 0;
}