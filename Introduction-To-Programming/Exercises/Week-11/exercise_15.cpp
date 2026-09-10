// Да се напише рекурсивна програма, която проверява дали даден низ е палиндром.
#include <iostream>
#include <cstring>

bool is_palindrome(char* str) {
    if (strlen(str) == 1 || strlen(str) == 0) {
        return true;
    }
    if (str[strlen(str) - 1] != str[0]) {
        return false;
    }
    str[strlen(str) - 1] = '\0';
    return is_palindrome(str + 1);
}

int main() {
    char str_1[4] = "121";
    char str_2[5] = "1212";
    std::cout << is_palindrome(str_1) << std::endl;
    std::cout << is_palindrome(str_2) << std::endl;
    return 0;
}