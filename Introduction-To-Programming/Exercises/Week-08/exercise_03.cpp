// Даден е низ. Да се напише програма, която намира 
// броя на думите в низа. Дума е редица от символи. 
// Разделител между думите е символът интервал.
#include <iostream>

int get_string_words_count(const char* str) {
    int counter = 0;
    while (*str != '\0') {
        while (*str == ' ') {
            str += 1;
        }

        if (*str == '\0') {
            break;
        }

        while (*str != ' ' && *str != '\0') {
            str += 1;
        }
        counter += 1;
    }

    return counter;
}

int main() {
    std::cout << get_string_words_count("Hello my name is Yoan!") 
        << std::endl;
    return 0;
}