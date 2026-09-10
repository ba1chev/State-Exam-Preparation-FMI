// Дадена е матрица с размери NxM. Напишете програма, 
// която проверява дали всички диагонали от ляво на дясно са нарастващи.
#include <iostream>

bool check_matrix_diagonals(const int* const* array, int N, int M) {
    if (!array || N < 0 || M < 0) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    for (size_t i = 0; i < N; i++) {
        if (!array[i]) {
            std::cout << "Invalid function input" << std::endl;
            return false;
        }
    }
    
    for (size_t j = 0; j < M; j++) {
        int i = 0;
        int current_j = j;

        while (i + 1 < N && current_j + 1 < M) {
            if (array[i][current_j] > array[i + 1][current_j + 1]) {
                return false;
            }
            i += 1;
            current_j += 1;
        }
    }
    
    for (size_t i = 0; i < N; i++) {
        int j = 0;
        int current_i = i;

        while (current_i + 1 < N && j + 1 < M) {
            if (array[current_i][j] > array[current_i + 1][j + 1]) {
                return false;
            }
            current_i += 1;
            j += 1;
        }
    }
    
    return true;
}

int main() {
    int N, M = 0;
    std::cin >> N >> M;
    if (N < 0 || M < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** array = new int*[N]{nullptr};
    for (size_t i = 0; i < N; i++) {
        array[i] = new int[M]{};
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            std::cin >> array[i][j];
        }
    }
    std::cout << check_matrix_diagonals(array, N, M) << std::endl;

    for (size_t i = 0; i < N; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}