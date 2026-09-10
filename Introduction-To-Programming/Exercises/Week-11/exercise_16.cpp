// Да се напише рекурсивна програма, която проверява дали 
// редицатаа0, а1, …, аn-1 се състои от различни елементи.
#include <iostream>

bool contains(const int* array, const int value, int* final_address) {
    if (array == final_address) {
        return false;
    }
    if (*array == value) {
        return true;
    }

    return contains(array + 1, value, final_address);
}

bool contains_unique(const int* array, int* final_address) {
    if (array == final_address) {
        return false;
    }
    if (contains(array + 1, *array, final_address)) {
        return true;
    }
    return contains_unique(array + 1, final_address);
}

int main() {
    int array_1[3] = {1, 2, 3};
    int array_2[3] = {1, 2, 2};
    std::cout << contains_unique(array_1, &array_1[2] + 1) << std::endl;
    std::cout << contains_unique(array_2, &array_2[2] + 1) << std::endl;
    return 0;
}
