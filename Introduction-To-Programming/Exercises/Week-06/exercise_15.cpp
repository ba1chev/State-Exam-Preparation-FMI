// Дадени са два сортирани масива съответно с N и M числа. 
// Слейте ги в нов сортиран масив.
#include <iostream>

void merge_two_sorted(const int* array_1, const int* array_2, int* result,
    const int size_1, const int size_2) {
    if (!array_1 || !array_2 || !result || size_1 < 0 || size_2 < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int left_ptr = 0;
    int right_ptr = 0;
    int current_index = 0;
    while (left_ptr < size_1 && right_ptr < size_2) {
        if (array_1[left_ptr] <= array_2[right_ptr]) {
            result[current_index] = array_1[left_ptr];
            left_ptr += 1;
        } else {
            result[current_index] = array_2[right_ptr];
            right_ptr += 1;
        }
        current_index += 1;
    }

    while (left_ptr < size_1) {
        result[current_index] = array_1[left_ptr];
        current_index += 1;
        left_ptr += 1;
    }

    while (right_ptr < size_2) {
        result[current_index] = array_2[right_ptr];
        current_index += 1;
        right_ptr += 1;
    }
}

int main() {
    int array_1[5] = {1, 3, 6, 7, 8};
    int array_2[7] = {2, 4, 5, 7, 9, 11, 12};
    int* result = new int[12] {};
    merge_two_sorted(array_1, array_2, result, 5, 7);

    for (size_t i = 0; i < 12; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    delete[] result;
    result = nullptr;
    return 0;
}