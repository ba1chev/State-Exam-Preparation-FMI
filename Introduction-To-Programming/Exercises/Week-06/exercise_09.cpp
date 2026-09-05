// Да се състави програма, която установява дали редицата от цели числа 
// а0, а1, а2, …, аn-1 е монотонно намаляваща (0 < n < 50) .
#include <iostream>

bool is_monotonic_decrease(const int* array, int size) {
    if(!array || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    int prev_number = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] - prev_number > 0) {
            return false;
        }
        prev_number = array[i];
    }
    
    return true;
}

int main() {
    int array_1[] = {10, 8, 6, 4, 2};
    int array_2[] = {10, 8, 9, 4, 2};
    int size_1 = 5;
    int size_2 = 5;

    std::cout << is_monotonic_decrease(array_1, size_1) << std::endl;
    std::cout << is_monotonic_decrease(array_2, size_2) << std::endl;
    return 0;
}