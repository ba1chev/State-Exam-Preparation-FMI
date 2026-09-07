// Дадени са матриците A и B, с размери NxM и PxQ. Да се изведе произведението на A и B, 
// ако това е възможно, или да се изведе съобщение, че не е.
#include <iostream>

int main() {
    const int m1_rows = 4;
    const int m1_cols = 3;
    const int m2_rows = 3; 
    const int m2_cols = 2;
    int matrix_1[m1_rows][m1_cols] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 1, 1}};
    int matrix_2[m2_rows][m2_cols] = {{6, 7}, {8, 9}, {1, 2}};
    int result_matrix[m1_rows][m2_cols];
    
    if (m1_cols != m2_rows) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < m1_rows; i++) {
        for (size_t j = 0; j < m2_cols; j++) {
            result_matrix[i][j] = 0;
            for (size_t k = 0; k < m1_cols; k++) {
                result_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    
    for (size_t i = 0; i < m1_rows; i++) {
        for (size_t j = 0; j < m2_cols; j++) {
            std::cout << result_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}