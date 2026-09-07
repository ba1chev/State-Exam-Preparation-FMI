// Да се състави функция, която приема като параметър низ с 
// произволна дължина и връща като резултат позициите на двойката 
// еднакви символи, които са максимално отдалечени един от друг. 
// Ако в низа съществуват няколко двойки максимално отдалечени 
// символи, функцията да връща позициите на най-ляво разположената 
// двойка. Счита се, че номерата на позициите започват от 0.
#include <iostream>

int get_str_size(const char* str) {
    if (!str) {
        std::cout << "Invalid function input" << std::endl;
        return -1;
    }

    int result_size = 0;
    while (*str != '\0') {
        str += 1;
        result_size += 1;
    }
    return result_size;
}

void find_largest_indexes_diff(const char* str) {
    if (!str) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int first[256]{};
    int last[256]{};
    for (size_t i = 0; i < 256; i++) {
        first[i] = -1;
        last[i] = -1;
    }

    int size = get_str_size(str);
    for (size_t i = 0; i < size; i++) {
        int c = (unsigned char)str[i];
        if (first[c] == -1) {
            first[c] = i;
        }
        last[c] = i;
    }

    int result_first = -1;
    int result_last = -1;
    int max_diff = -1;
    for (size_t i = 0; i < 256; i++) {
        if (first[i] != -1 && last[i] != first[i]) {
            int diff = last[i] - first[i];
            if (diff > max_diff) {
                max_diff = diff;
                result_first = first[i];
                result_last = last[i];
            }
        }
    }

    std::cout << result_first << " " << result_last << std::endl;
}

int main() {
    find_largest_indexes_diff("this is just a simple example");
    return 0;
}