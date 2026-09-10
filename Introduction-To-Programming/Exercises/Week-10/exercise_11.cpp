// Да се състави програма, която установява дали целочисленият 
// двумерен масив А с размерност mxn съдържа отрицателен елемент.
#include <iostream>

bool have_negative(const int* const* array, int N, int M) {
    if (!array || N < 0 || M < 0) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    for (size_t i = 0; i < N; i++) {
        if (!array[i]) {
            std::cout << "Invalid function input" << std::endl;
            return false;
        }

        for (size_t j = 0; j < M; j++) {
            if (array[i][j] < 0) {
                return true;
            }
        }
    }
    return false;
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
    std::cout << have_negative(array, N, M) << std::endl;

    for (size_t i = 0; i < N; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}