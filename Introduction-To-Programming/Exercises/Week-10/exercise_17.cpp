// Дадени са матриците A и B, с размери NxM и PxQ. Да се изведе произведението на A и B, 
// ако това е възможно, или да се изведе съобщение, че не е.
#include <iostream>

int** multiplication_of_matrix(const int* const* left, int N_1, int M_1,
    const int* const* right, int N_2, int M_2) {
    if (!left || !right || N_1 < 0 || N_2 < 0 
        || M_1 < 0 || M_2 < 0 || M_1 != N_2) {
        std::cout << "Invalid function input" << std::endl; 
        return nullptr;
    }

    int** result = new int*[N_1]{nullptr};
    for (size_t i = 0; i < N_1; i++) {
        result[i] = new int[M_2]{};
    }
    
    for (size_t i = 0; i < N_1; i++) {
        for (size_t j = 0; j < M_2; j++) {
            result[i][j] = 0;
            for (size_t k = 0; k < M_1; k++) {
                result[i][j] += left[i][k] * right[k][j];
            }
        }
    }
    
    return result;
}

int main() {
    int N_1, N_2, M_1, M_2 = 0;
    std::cin >> N_1 >> N_2 >> M_1 >> M_2;
    if (N_1 < 0 || N_2 < 0 || M_1 < 0 || M_2 < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** left = new int*[N_1]{nullptr};
    for (size_t i = 0; i < N_1; i++) {
        left[i] = new int[M_1]{};
    }
    for (size_t i = 0; i < N_1; i++) {
        for (size_t j = 0; j < M_1; j++) {
            std::cin >> left[i][j];
        }
    }
    
    int** right = new int*[N_2]{nullptr};
    for (size_t i = 0; i < N_2; i++) {
        right[i] = new int[M_2]{};
    }
    for (size_t i = 0; i < N_2; i++) {
        for (size_t j = 0; j < M_2; j++) {
            std::cin >> right[i][j];
        }
    }

    int** result = multiplication_of_matrix(left, N_1, M_1, right, N_2, M_2);
    if (result) {
        for (size_t i = 0; i < N_1; i++) {
            for (size_t j = 0; j < M_2; j++) {
                std::cout << result[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    for (size_t i = 0; i < N_1; i++) {
        delete[] left[i];
        left[i] = nullptr;
    }
    for (size_t i = 0; i < N_2; i++) {
        delete[] right[i];
        right[i] = nullptr;
    }
    if (result) {
        for (size_t i = 0; i < N_1; i++) {
            delete[] result[i];
            result[i] = nullptr;
        }
    }
    delete[] left;
    delete[] right;
    delete[] result;
    left = nullptr;
    right = nullptr;
    result = nullptr;
    return 0;
}