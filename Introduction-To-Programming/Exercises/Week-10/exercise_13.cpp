// Триъгълна матрица наричаме такава квадратна матрица, 
// която има само нули под или над главния или вторичния си диагонал. 
// Даден е двумерен масив с nxn елемента. Да се провери дали е триъгълна матрица.
#include <iostream>

bool is_diagonal_matrix(const int* const* array, int N) {
    if (!array || N < 0) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    for (size_t i = 0; i < N; i++) {
        if (!array[i]) {
            std::cout << "Invalid function input" << std::endl;
            return false;
        }
    }
    
    bool pred_1 = true;
    bool pred_2 = true;
    bool pred_3 = true;
    bool pred_4 = true;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (j > i && array[i][j] != 0) {
                pred_2 = false;
            }
            if (i > j && array[i][j] != 0) {
                pred_1 = false;
            }
            if (i + j > N - 1 && array[i][j] != 0) {
                pred_3 = false;
            }
            if (i + j < N - 1 && array[i][j] != 0) {
                pred_4 = false;
            }
        }
    }

    if ((pred_1 && pred_2) || (pred_3 && pred_4)) {
        return true;
    }
    return pred_1 || pred_2 || pred_3 || pred_4;
}

int main() {
    int N;
    std::cin >> N;
    if (N < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** array = new int*[N]{nullptr};
    for (size_t i = 0; i < N; i++) {
        array[i] = new int[N]{};
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            std::cin >> array[i][j];
        }
    }
    std::cout << is_diagonal_matrix(array, N) << std::endl;

    for (size_t i = 0; i < N; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}