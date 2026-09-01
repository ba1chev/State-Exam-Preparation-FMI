// Да се състави програма, която прочита от клавиатурата голяма латинска буква и 
// извежда голямата латинска буква, която е симетрично разположена 
// спрямо въведената, по отношение на средата на латинската азбука
#include <iostream>

int main() {
    char latin_letter = 'a';
    int middle_letter_ascii = ((int)'A' + (int)'Z') / 2;
    std::cin >> latin_letter;
    bool is_latin = (latin_letter >= 'A' && latin_letter <= 'Z');

    if (!is_latin) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    std::cout << char('A' + 'Z' - latin_letter) << std::endl;
    return 0;
}
