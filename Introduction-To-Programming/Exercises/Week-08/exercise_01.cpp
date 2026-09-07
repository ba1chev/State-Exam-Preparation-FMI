// Да се напише програма, която установява дали даден низ е палиндром, т.е. 
// четен отляво надясно и отдясно наляво е един и същ.
#include <iostream>

bool is_palindrome(const char* str, int size) {
    for (size_t i = 0; i < size / 2; i++) {
        if (str[i] != str[size - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << is_palindrome("abc", 3) << std::endl;
    std::cout << is_palindrome("abba", 4) << std::endl;
    return 0;
}