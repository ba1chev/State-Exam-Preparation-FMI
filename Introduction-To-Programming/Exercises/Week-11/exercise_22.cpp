// Да се дефинира функция, която приема низ A и низ B и проверява
// дали низ B се съдържа в низ А.
#include <iostream>
#include <cstring>

bool is_prefix(const char* str_1, const char* str_2) {
    if (!str_1 || !str_2) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    if (*str_2 == '\0') {
        return true;
    }
    if (*str_1 != *str_2) {
        return false;
    }

    return is_prefix(str_1 + 1, str_2 + 1);
}

bool contains_string(const char* left_str, const char* right_str) {
    if (!left_str || !right_str) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    if (is_prefix(left_str, right_str)) {
        return true;
    }
    if (*left_str == '\0') {
        return false;
    }

    return contains_string(left_str + 1, right_str);
}

int main() {
    char str_1[6] = "tests";
    char str_2[4] = "sts";
    char str_3[5] = "stsa";
    std::cout << contains_string(str_1, str_2) << std::endl;
    std::cout << contains_string(str_1, str_3) << std::endl;
    return 0;
}