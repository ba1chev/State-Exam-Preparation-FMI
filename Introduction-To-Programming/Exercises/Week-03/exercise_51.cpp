// Напишете програма, която приема естествено число n > 9 и 
// извежда като резултат броя цифри на числото, сумата на първата 
// и последната цифра, числото, което се получава при размяна на 
// първата и последната цифра, произведението на всичките цифри 
// на числото, числото записано наобратно, съобщение дали числото 
// е или не е палиндром, както и информация за това коя цифра по 
// колко пъти се среща в даденото число.
#include <iostream>

int get_digits_count(int number) {
    int counter = 0;
    while (number != 0) {
        counter += 1;
        number /= 10;
    }
    return counter;
}

int get_first_digit(int number) {
    int iter = 1;
    int digits_count = get_digits_count(number);
    for (size_t i = 1; i < digits_count; i++) {
        iter *= 10;
    }

    return number / iter;

}

int get_last_digit(int number) {
    return number % 10;

}

int get_number_after_swap_first_last_digit(int number) {
    int current_iteration = 0;
    int first_digit = get_first_digit(number);
    int last_digit = get_last_digit(number);
    int count_of_digits = get_digits_count(number);
    int new_number = 0;
    int iter = 1;

    while (number != 0) {
        int current_digit = number % 10;
        number /= 10;
        iter *= 10;
        current_iteration += 1;

        if (current_iteration == count_of_digits ||
            current_iteration == 1) {
            continue;
        }
        new_number += (iter / 10) * current_digit;
    }

    new_number += first_digit;
    new_number += (iter / 10) * last_digit;
    return new_number;
}

int get_reverse_number(int number) {
    int buffer[1024];
    int current_index = 0;
    int iter = 1;

    while (number != 0) {
        buffer[current_index] = number % 10;
        current_index += 1;
        iter *= 10;
        number /= 10;
    }

    iter /= 10;
    int reversed_number = 0;
    for (size_t i = 0; i < current_index; i++) {
        reversed_number += iter * buffer[i];
        iter /= 10;
    }
    
    return reversed_number;
}

int get_product_of_digits(int number) {
    int product = 1;
    while (number != 0) {
        product *= number % 10;
        number /= 10;
    }
    return product;
}

int sum_first_last_digit(int number) {
    return get_first_digit(number) + get_last_digit(number);
}

bool is_palindrome(int number) {
    int buffer[1024];
    int current_index = 0;

    while (number != 0) {
        buffer[current_index] = number % 10;
        current_index += 1;
        number /= 10;
    }

    for (size_t i = 0; i < current_index / 2; i++) {
        if (buffer[current_index - i - 1] != buffer[i]) {
            return false;
        } 
    }
    
    return true;
}

void get_number_digits_info(int number) {
    int buffer[10];
    for (size_t i = 0; i < 10; i++) {
        buffer[i] = 0;
    }
    
    while (number != 0) {
        buffer[number % 10] += 1;
        number /= 10;
    }

    for (size_t i = 0; i < 10; i++) {
        std::cout << "The digit " << i << " has " << 
            buffer[i] << " occurrences" << std::endl;
    }
}

int main() {
    int number = 0;
    std::cin >> number;
    if (number <= 9) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << "Digits count is: " << get_digits_count(number) << std::endl;
    std::cout << "Sum of first and last digit is: " << sum_first_last_digit(number) << std::endl;
    std::cout << "Product of all digits is: " << get_product_of_digits(number) << std::endl;
    std::cout << "New number after swapping firt and last digits is: " <<
        get_number_after_swap_first_last_digit(number) << std::endl;
    std::cout << "New reversed number is: " << get_reverse_number(number) << std::endl;
    std::cout << "Number is palindrome: " << is_palindrome(number) << std::endl;
    get_number_digits_info(number);
    return 0;
}