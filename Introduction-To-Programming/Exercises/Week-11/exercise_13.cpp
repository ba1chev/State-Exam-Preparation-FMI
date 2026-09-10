// Да се напише рекурсивна програма, която проверява дали 
// редицата а0, а1, …, аn-1 е монотонно растяща.
#include <iostream>

bool is_monotonic(const int prev, const int* array, int* final_address) {
    if (array == final_address) {
        return true;
    }
    if (*array < prev) {
        return false;
    }
    return is_monotonic(*array, array + 1, final_address);
}

int main() {
    int array_1[3] = {1, 2, 3};
    int array_2[3] = {1, -1, 3};
    std::cout << is_monotonic(array_1[0], array_1 + 1, &(array_1[2]) + 1) << std::endl;
    std::cout << is_monotonic(array_2[0], array_2 + 1, &(array_2[2]) + 1) << std::endl;
    return 0;
}