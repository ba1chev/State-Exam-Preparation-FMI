// Да се състави програма, която проверява, има ли в редицата от 
// цели числа а0, а1, а2, …, аn-1 (0 < n < 51) два последователни нулеви елемента.
#include <iostream>

bool has_two_zeros(const int* array, int size) {
    if (!array || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    int prev_number = array[0];
    for (size_t i = 1; i < size; i++) {
        if (array[i] == 0 && array[i] == prev_number) {
            return true;
        }
        prev_number = array[i];
    }
    
    return false;
}

int main() {
    int array_1[51] = {1, 2, 3, 4, 5};
    int array_2[51] = {1, 2, 0, 0, 5};

    std::cout << has_two_zeros(array_1, 5) << std::endl;
    std::cout << has_two_zeros(array_2, 5) << std::endl;
    return 0;
}
