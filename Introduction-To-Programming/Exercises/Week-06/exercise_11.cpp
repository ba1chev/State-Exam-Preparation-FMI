// Даден е масив от тип char съдържащ n символа (0 < n < 50) . 
// Да се състави програма, която определя дали масива е симетричен, т.е. 
// прочетен отляво надясно и отдясно наляво е един и същ.
#include <iostream>

bool is_palindrome(const char* array, int size) {
    if (!array || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    for (size_t i = 0; i < size / 2; i++) {
        if (array[i] != array[size - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char array_1[4] = "abc";
    char array_2[4] = "aba";

    std::cout << is_palindrome(array_1, 3) << std::endl;
    std::cout << is_palindrome(array_2, 3) << std::endl;
    return 0;
}