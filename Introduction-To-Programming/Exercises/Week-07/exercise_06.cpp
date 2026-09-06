// Дадена е квадратна реална матрица А с размерност kxk. 
// Да се състави програма, която намира и извежда неотрицателните елементи върху главния диагонал.
#include <iostream>

void find_non_negative_on_diagonal(const int* const* array, int k) {
    if (!array || k < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < k; i++) {
        if (array[i][i] >= 0) {
            std::cout << array[i][i] << std::endl;
        }
    }
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
    find_non_negative_on_diagonal(array, k);

    for (size_t i = 0; i < k; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}