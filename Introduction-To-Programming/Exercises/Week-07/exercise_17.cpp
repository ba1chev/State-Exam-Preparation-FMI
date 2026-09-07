// Изхождайки от определението за магически квадрат (сумата по редове, колони и двата 
// диагонала да е равна), ще дефинираме магически палиндром като матрица, съдържаща 
// палиндроми по редовете, колоните и двата си диагонала. По зададено число N (0<N<10) 
// определете дали дадена матрица от символи (размер NxN) е магически палиндром.
#include <iostream>

bool is_palindrome(const char* array, int size) {
    for (size_t i = 0; i < size / 2; i++) {
        if (array[i] != array[size - i - 1]) {
            return false;
        }
    }
    
    return true;
}

bool is_matrix_palindrome(const char* const* matrix, int count_of_rows, int count_of_cols) {
    for (size_t i = 0; i < count_of_rows; i++) {
        if (!is_palindrome(matrix[i], count_of_cols)) {
            return false;
        }
    }
    
    char* current_column = new char[count_of_rows]{};
    int current_index = 0;
    for (size_t i = 0; i < count_of_cols; i++) {
        for (size_t j = 0; j < count_of_rows; j++) {
            current_column[current_index] = matrix[j][i];
            current_index += 1;
        }

        if (!is_palindrome(current_column, count_of_rows)) {
            delete[] current_column;
            current_column = nullptr;
            return false;
        }
        current_index = 0;
    }
    delete[] current_column;
    current_column = nullptr;

    current_index = 0;
    char* current_diagonal = new char[count_of_rows]{};
    for (size_t i = 0; i < count_of_rows; i++) {
        for (size_t j = 0; j < count_of_cols; j++) {
            if (i == j) {
                current_diagonal[current_index] = matrix[i][j];
                current_index += 1;
            }
        }
    }
    if (!is_palindrome(current_diagonal, count_of_rows)) {
        delete[] current_diagonal;
        current_diagonal = nullptr;
        return false;
    }

    current_index = 0;
    for (size_t i = 0; i < count_of_rows; i++) {
        for (size_t j = 0; j < count_of_cols; j++) {
            if (i + j == count_of_rows - 1) {
                current_diagonal[current_index] = matrix[i][j];
                current_index += 1;
            }
        }
    }
    if (!is_palindrome(current_diagonal, count_of_rows)) {
        delete[] current_diagonal;
        current_diagonal = nullptr;
        return false;
    }

    delete[] current_diagonal;
    current_diagonal = nullptr;
    return true;
}

int main() {
    int N = 0;
    std::cin >> N;
    if (N < 0) {
        std::cout << "Invaid input" << std::endl;
        return 1;
    }

    char** matrix = new char*[N]{nullptr};
    for (size_t i = 0; i < N; i++) {
        matrix[i] = new char[N]{};
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << is_matrix_palindrome(matrix, N, N) << std::endl; 

    for (size_t i = 0; i < N; i++) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    return 0;
}