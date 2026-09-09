// Напишете функция, която приема два указателя и определя 
// кой от тях има по-голяма стойност.
#include <iostream>

int bigger(const int* left_ptr, const int* right_ptr) {
    if (!left_ptr || !right_ptr) {
        std::cout << "Invalid function input" << std::endl;
        return -1;
    }

    return (*left_ptr + *right_ptr + std::abs(*left_ptr - *right_ptr)) / 2;
}

int main() {
    int left = 3;
    int right = 4;
    
    std::cout << bigger(&left, &right) << std::endl;
    return 0;
}