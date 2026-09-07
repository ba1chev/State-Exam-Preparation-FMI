// Дадена е матрица А с размер Nx2. 
// Сортирайте редовете й в нарастващ ред по първия елемент. 
// Ако първите елементи са равни, по вторите. Изведете я.
#include <iostream>

bool compare_two_rows(const int* row_1, const int* row_2) {
    if (row_1[0] == row_2[0]) {
        return row_1[1] > row_2[1];
    }
    return row_1[0] > row_2[0];
}

void bubble_sort(int** matrix, int count_of_rows, int count_of_cols) {
    if (!matrix || count_of_rows <= 0 || count_of_cols != 2) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < count_of_rows - 1; i++) {
        for (size_t j = 0; j < count_of_rows - i - 1; j++) {
            if (compare_two_rows(matrix[j], matrix[j + 1])) {
                int* temp = matrix[j];
                matrix[j] = matrix[j + 1];
                matrix[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N = 0;
    std::cin >> N;
    if (N < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** matrix = new int*[N]{};
    for (size_t i = 0; i < N; i++) {
        matrix[i] = new int[2]{};
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < 2; j++) {
            std::cin >> matrix[i][j];
        }
    }
    bubble_sort(matrix, N, 2);

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < 2; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (size_t i = 0; i < N; i++) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    return 0;
}
