// Да се състави програма, която прочита от клавиатурата латинска буква 
// голяма и извежда поредния й номер в латинската азбука.
#include <iostream>

int main() {
    char latin_letter = 'a';
    std::cin >> latin_letter;
    bool is_latin = (latin_letter >= 'A' && latin_letter <= 'Z');

    if (!is_latin) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << (int)latin_letter - 65 + 1 << std::endl;
    return 0;
}