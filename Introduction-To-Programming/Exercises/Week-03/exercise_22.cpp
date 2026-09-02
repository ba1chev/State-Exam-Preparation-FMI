// Да се напише програма, която приема 2 числа, които символизират карти, 
// където 11 е вале, 12 е дама, 13 е поп, а 1 е асо. Да се изведе дали 
// въпросната ръка преминава 21 по правилата на играта Блек Джек.
#include <iostream>

bool check_valid_card(const int number) {
    return number >= 1 && number <= 13;
}

int get_card_value(const int number) {
    if (number == 11 || number == 12 || number == 13) {
        return 10;
    }
    return number;
}

int main() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    if (!check_valid_card(a) || !check_valid_card(b)) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int sum = get_card_value(a) + get_card_value(b);
    std::cout << (bool)(sum > 21) << std::endl;
    return 0;
}