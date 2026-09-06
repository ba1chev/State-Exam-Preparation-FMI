// Дадена е квадратна реална матрица А с размерност nxn . 
// Да се състави програма, която намира сумата от елементите под главния диагонал (включително главният диагонал).
#include <iostream>

void find_sum_under_diagonal(const int* const* array, int k) {
    if (!array || k < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int result_sum = 0;
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < k; j++) {
            if (i >= j) {
                result_sum += array[i][j];
            }
        }
    }
    std::cout << result_sum << std::endl;
}

int main() {
    int k = 0;
    std::cin >> k;
    if (k < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** array = new int*[k]{};
    for (size_t i = 0; i < k; i++) {
        array[i] = new int[k]{};
    }
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < k; j++) {
            std::cin >> array[i][j];
        }
    }
    find_sum_under_diagonal(array, k);

    for (size_t i = 0; i < k; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}