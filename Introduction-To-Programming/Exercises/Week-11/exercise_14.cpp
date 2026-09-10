// Да се напише рекурсивна програма, която проверява дали елементът x 
// принадлежи на сортирана редицата а0, а1, …, аn-1 (двоично търсене)
#include <iostream>

bool contains(const int* array, const int left, const int right, const int x) {
    if (left >= right) {
        return false;
    }
    int middle = left + (right - left) / 2;
    if (array[middle] == x) {
        return true;
    } else if (array[middle] > x) {
        return contains(array, left, middle - 1, x);
    } else {
        return contains(array, middle + 1, right, x);
    }
}

int main() {
    int array[3] = {1, 2, 3};
    std::cout << contains(array, 0, 3, 2) << std::endl;
    std::cout << contains(array, 0, 3, 4) << std::endl;
    return 0;
}