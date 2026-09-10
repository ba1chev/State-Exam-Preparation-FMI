// Да се напише програма, която приема параметър естествено 
// число n и масив от естествени числа. Да се изведе дали е възможно 
// с до n-на брой махания на първия или последния елемент от масив 
// да се получи палиндром.
#include <iostream>

bool can_make_palindrome(const int* array, int left, int right, int n) {
    if (left >= right) {
        return true;
    }
    if (n == 0) {
        return false;
    }
    if (array[left] == array[right]) {
        return can_make_palindrome(array, left + 1, right - 1, n);
    }

    return can_make_palindrome(array, left + 1, right, n - 1) ||
           can_make_palindrome(array, left, right - 1, n - 1);
}

bool can_make_palindrome(const int* array, int size, int n) {
    if (!array || size < 0 || n < 0) {
        return false;
    }

    return can_make_palindrome(array, 0, size - 1, n);
}

int main() {
    int array_1[4] = {1, 1, 2, 1};
    int array_2[6] = {1, 1, 2, 1, 5, 7};
    int array_3[2] = {1, 2};

    std::cout << can_make_palindrome(array_1, 4, 1) << std::endl;
    std::cout << can_make_palindrome(array_2, 6, 3) << std::endl;
    std::cout << can_make_palindrome(array_3, 2, 1) << std::endl;
    return 0;
}