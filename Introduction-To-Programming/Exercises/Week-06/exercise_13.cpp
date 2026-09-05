// Дадена са редицата от реални числа а0, а1, а2, …, аn-1 (0 < n < 51) . 
// Да се състави програма, която сортира във възходящ ред елементите на редицата.
#include <iostream>

void bubble_sort(int* array, int size) {
    if (!array || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

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

int main() {
    int array[5] = {1, 3, 2, 5, 4};
    bubble_sort(array, 5);

    for (size_t i = 0; i < 5; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}