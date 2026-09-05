// Да се състави програма, която установява дали редицата от 
// цели числа а0, а1, а2, …, аn-1 се състои от различни елементи (0 < n < 50) .
#include <iostream>
#include <cstring>

void bubble_sort(int* array, int size) {
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

bool has_different_elements(const int* array, const int size) {
    if (!array || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    int* new_array = new int[size]{};
    std::memcpy(new_array, array, size * sizeof(int));
    bubble_sort(new_array, size);

    for (size_t i = 0; i < size; i++) {
        if ((i + 1 != size) && (new_array[i] == new_array[i + 1])) {
            delete[] new_array;
            new_array = nullptr;
            return false;
        }
    }
    
    delete[] new_array;
    new_array = nullptr;
    return true;
}

int main() {
    int array_1[50] = {1, 2, 3, 4, 5};
    int array_2[50] = {1, 2, 5, 4, 5};
    int size_1 = 5;
    int size_2 = 5;

    std::cout << has_different_elements(array_1, size_1) << std::endl;
    std::cout << has_different_elements(array_2, size_2) << std::endl;
    return 0;
}