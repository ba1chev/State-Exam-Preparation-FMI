#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;

    if (number < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    if (number == 0) {
        std::cout << "sum=0 p=0 avr=0" << std::endl;
        return 0;
    }

    int digits_sum = 0;
    int digits_product = 1;
    int digit_counter = 0;
    while (number != 0) {
        int current_digit = number % 10;
        digit_counter += 1;
        digits_product *= current_digit;
        digits_sum += current_digit;
        number /= 10;
    }

    float avarage_sum = digits_sum / (digit_counter + 0.f);
    std::cout << "sum=" << digits_sum << 
        " p=" << digits_product << " avr=" <<
        avarage_sum << std::endl;
    return 0;
}

