// Напишете подпрограма, определя колко пъти символният низ S2 се съдържа в S1.
#include <iostream>

int get_substring_count(const char* left_str, const char* right_str) {
    int counter = 0;
    while (*left_str != '\0') {
        if (*left_str == *right_str) {
            const char* temp_ptr_1 = left_str;
            const char* temp_ptr_2 = right_str;
            while (*temp_ptr_1 != '\0' && *temp_ptr_2 != '\0' && 
                *temp_ptr_1 == *temp_ptr_2) {
                temp_ptr_1 += 1;
                temp_ptr_2 += 1;
            }

            if (*temp_ptr_2 == '\0') {
                counter += 1;
            }
        }
        left_str += 1;
    }

    return counter;
}

int main() {
    std::cout << get_substring_count("My name is yoan!", "yoan") << std::endl;
    std::cout << get_substring_count("yoanaayoanyoan", "yoan") << std::endl;
    std::cout << get_substring_count("aaa", "aa") << std::endl;
    return 0;
}