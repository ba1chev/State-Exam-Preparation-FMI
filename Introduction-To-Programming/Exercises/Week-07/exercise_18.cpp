// Дадена е матрица с размери NxM, 0 < N, M < 10. Напишете програма, 
// която проверява дали всички диагонали от ляво на дясно са нарастващи.
#include <iostream>

bool is_array_increasing(const int* array, int size) {
    for (size_t i = 1; i < size; i++) {
        if (array[i - 1] > array[i]) {
            return false;
        }
    }
    return true;
}

bool is_every_diagonal_increasing(const int* const* matrix, int N, int M) {
    int buffer[10]{};
    int current_index = 0;
    for (size_t j = 0; j < M; j++) {
        int current_row = 0;
        int current_col = j;

        while (current_row < N && current_col < M) {
            buffer[current_index] = matrix[current_row][current_col];
            current_row += 1;
            current_col += 1;
            current_index += 1;
        }

        if (!is_array_increasing(buffer, current_index)) {
            return false;
        }
        current_index = 0;
    }

    for (size_t i = 1; i < N; i++) {
        int current_row = i;
        int current_col = 0;

        while (current_row < N && current_col < M) {
            buffer[current_index] = matrix[current_row][current_col];
            current_row += 1;
            current_col += 1;
            current_index += 1;
        }

        if (!is_array_increasing(buffer, current_index)) {
            return false;
        }
        current_index = 0;
    }

    return true;
}

int main() {
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    if (N < 0 || M < 0 || N > 10 || M > 10) {
        std::cout << "Invaid input" << std::endl;
        return 1;
    }

    int** matrix = new int*[N]{nullptr};
    for (size_t i = 0; i < N; i++) {
        matrix[i] = new int[M]{};
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << is_every_diagonal_increasing(matrix, N, M) << std::endl;

    for (size_t i = 0; i < N; i++) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    return 0;
}