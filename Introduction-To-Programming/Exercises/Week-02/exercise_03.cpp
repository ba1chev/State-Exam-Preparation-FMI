// Да се състави програма, която прочита от клавиатурата две 
// латински букви и извежда сумата от съответните им ASCII-кодове.
#include <iostream>

int main() {
    char first_letter = 'a';
    char second_letter = 'b';
    std::cin >> first_letter >> second_letter;

    bool is_first_latin = (first_letter >= 'a' && first_letter <= 'z') ||
        (first_letter >= 'A' && first_letter <= 'Z');
    bool is_second_latin = (second_letter >= 'a' && second_letter <= 'z') ||
        (second_letter >= 'A' && second_letter <= 'Z');

    if (!is_first_latin || !is_second_latin) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << (int)first_letter + (int)second_letter << std::endl;
    return 0;
}