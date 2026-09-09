// Изречение е редица от символи, започваща с 
// главна буква и завършваща с ., ! или ?. Да се намери броят на 
// изреченията в даден текстов файл.
#include <iostream>
#include <fstream>

bool is_upper(const char ch) {
    return ch >= 'A' && ch <= 'Z';
}

int get_count_of_sentences(const char* str) {
    if (!str) {
        std::cout << "Invalid function input" << std::endl;
        return -1;
    }

    int counter = 0;
    while (*str != '\0') {
        if (is_upper(*str)) {
            while (*str != '\0' && *str != '.'
                && *str != '!' && *str != '?') {
                str += 1;
            }
            if (*str == '\0') {
                break;
            }
            counter += 1;
        }
        str += 1;
    }

    return counter;
}

int main() {
    std::ifstream ifs("file.txt");
    int counter = 0;
    char buffer[1024]{};
    while (ifs.getline(buffer, sizeof(buffer))) {
        counter += get_count_of_sentences(buffer);
    }

    ifs.close();
    std::cout << counter << std::endl;
    return 0;
}