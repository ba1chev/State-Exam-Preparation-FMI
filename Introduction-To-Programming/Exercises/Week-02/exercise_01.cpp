// Да се състави програма, която прочита 
// от клавиатурата цяло число от 0 до 255 и извежда 
// съответстващия му символ според ASCII таблицата.
#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;

    if (number < 0 || number > 255) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << (char)number << std::endl;
    return 0;
}