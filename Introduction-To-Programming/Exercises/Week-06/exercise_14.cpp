// Нека А е сортиран във възходящ ред масив от елементи 
// а0, а1, а2, …, аn-1 (0 < n < 51). Да се състави програма, 
// която установява дали елемента х се съдържа в масива (двоично търсене).
#include <iostream>

bool binary_search(const int* array, int size, const int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (array[middle] > target) {
            right = middle - 1;
        } else if (array[middle] < target) {
            left = middle + 1;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int A_1[5] = {1, 2, 3, 4, 5};
    int A_2[5] = {1, 2, 3, 3, 5};

    std::cout << binary_search(A_1, 5, 4) << std::endl;
    std::cout << binary_search(A_2, 5, 4) << std::endl;
    return 0;
}