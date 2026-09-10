// Да се напише рекурсивна програма, която проверява 
// дали елементът x принадлежи на редицата а0, а1, …, аn-1 
// (последователно търсене)
#include <iostream>

bool contains(const int* array, int* final_address, const int x) {
    if (array == final_address) {
        return false;
    }
    if (*array == x) {
        return true;
    }
    return contains(array + 1, final_address, x);
}

int main() {
    int array[3] = {1, 2, 3};
    std::cout << contains(array, &(array[2]) + 1, 1) << std::endl;
    std::cout << contains(array, &(array[2]) + 1, 4) << std::endl;
    return 0;
}