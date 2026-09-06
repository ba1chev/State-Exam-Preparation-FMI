// Триъгълна матрица наричаме такава квадратна матрица, 
// която има само нули под или над главния или вторичния си диагонал. 
// Даден е двумерен масив с nxn елемента. Да се провери дали е 
// триъгълна матрица. Ограничения: 2 <= n <= 100
#include <iostream>

bool is_traingle(const int* const* array, int k) {
    if (!array || k < 0) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    bool pred_1 = true;
    bool pred_2 = true;
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < k; j++) {
            if (i > j && array[i][j] != 0) {
                pred_1 = false;
                break;
            }
        }
    }
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < k; j++) {
            if (i + j < k - 1 && array[i][j] != 0) {
                pred_2 = false;
                break;
            }
        }
    }
    return pred_1 || pred_2;
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
    if (is_traingle(array, k)) {
        std::cout << "yes" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }

    for (size_t i = 0; i < k; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}
