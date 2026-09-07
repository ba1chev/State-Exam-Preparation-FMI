// Даден е низ, образуван от главни латински букви. Да се 
// напише програма, която установява дали буквите, участващи в низа са различни.
#include <iostream>

bool are_lettes_unique(const char* str) {
    const char* temp_ptr = str;
    while (*temp_ptr != '\0') {
        if (!(*temp_ptr >= 'A' && *temp_ptr <= 'Z')) {
            std::cout << "Invalid function input" << std::endl;
            return false;
        }
        temp_ptr += 1;
    }

    int buffer[26]{0};
    for (size_t i = 0; i < 26; i++) {
        buffer[i] = 0;
    }
    
    while (*str != '\0') {
        buffer[(int)*str - (int)'A'] += 1;
        str += 1;
    }

    for (size_t i = 0; i < 26; i++) {
        if (buffer[i] > 1) {
            return false;
        }
    }
    
    return true;
}

int main() {
    std::cout << are_lettes_unique("ABCDE") << std::endl;
    std::cout << are_lettes_unique("ABCDEA") << std::endl;
    return 0;
}