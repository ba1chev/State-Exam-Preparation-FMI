// Напишете програма, която въвежда знаков низ S и като резултат отпечатва 
// онези малки латински букви, които не се съдържат в низа.
#include <iostream>

void print_non_containing(const char* str) {
    if (!str) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    bool buffer[26]{false};
    
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            buffer[(int)*str - (int)'a'] = true;
        }
        str += 1;
    }

    for (size_t i = 0; i < 26; i++) {
        if (!buffer[i]) {
            std::cout << (char)(i + (int)'a') << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    print_non_containing("123");
    print_non_containing("abcd");
    return 0;
}