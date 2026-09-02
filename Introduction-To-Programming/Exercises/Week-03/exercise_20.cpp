// Да се напише програма, която получава 3 цифри и изписва на 
// конзолата най-голямото число, което може да се получи от тях. 
// Помислете за някой специфичен вход.
#include <iostream>

int get_max(int left, int right) {
    return (left + right + std::abs(left - right)) / 2;
}

bool is_digit(int number) {
    return (number >= 0) && (number <= 9);
}

int main() {
    int a = 0, b = 0, c = 0;
    std::cin >> a >> b >> c;
    if (!is_digit(a) || !is_digit(b) || !is_digit(c) || 
        (a == b && b == c && c == 0)) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int first_number = get_max(get_max(a, b), c);
    if (first_number == a) {
        int second_number = get_max(b, c);
        if (second_number == b) {
            std::cout << a << b << c << std::endl;
        } else {
            std::cout << a << c << b << std::endl;
        }
    } else if (first_number == b) {
        int second_number = get_max(a, c);
        if (second_number == a) {
            std::cout << b << a << c << std::endl;
        } else {
            std::cout << b << c << a << std::endl;
        }
    } else if (first_number == c) {
        int second_number = get_max(a, b);
        if (second_number == a) {
            std::cout << c << a << b << std::endl;
        } else {
            std::cout << c << b << a << std::endl;
        }
    }

    return 0;
}