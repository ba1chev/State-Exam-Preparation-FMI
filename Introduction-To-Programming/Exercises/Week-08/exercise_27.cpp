// Дума е редица от букви или число. 
// Да се намери броят на думите в даден текстов файл.
#include <iostream>
#include <fstream>

bool is_digit(const char ch) {
    return ch >= '0' && ch <= '9';
}

bool is_latin(const char ch) {
    return (ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z');
}

int get_words_count(const char* str) {
    if (!str) {
        std::cout << "Invalid function input" << std::endl;
        return -1;
    }

    int counter = 0;
    while (*str != '\0') {
        while (*str != '\0' && !is_latin(*str) && !is_digit(*str)) {
            str += 1;
        }

        if (*str != '\0' && (is_latin(*str) || is_digit(*str))) {
            while (*str != '\0' && (is_latin(*str) || is_digit(*str))) {
                str += 1;
            }
            counter += 1;
        }        
    }

    return counter;
}

int main() {
    std::ifstream ifs("file.txt");
    int counter = 0;
    char buffer[1024]{};
    while (ifs.getline(buffer, sizeof(buffer))) {
        counter += get_words_count(buffer);
    }

    ifs.close();
    std::cout << counter << std::endl;
    return 0;
}