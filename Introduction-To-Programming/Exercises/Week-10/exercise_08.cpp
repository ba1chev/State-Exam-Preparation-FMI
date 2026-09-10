// Да се състави програма, която намира и извежда минималният елемент на всеки 
// ред на двумерен масив. На първия ред от стандартния вход да се въведат 
// размерите на масива, а на следващите редове и самият масив.
#include <iostream>
#include <climits>
#include <cstdlib>

void find_min_element_per_row(const int* const* array, int N, int M) {
    if (!array || N < 0 || M < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < N; i++) {
        if (!array[i]) {
            std::cout << "Invalid function input" << std::endl;
            return;
        }

        int current_min_element = INT_MAX;
        for (size_t j = 0; j < M; j++) {
            current_min_element = (
                current_min_element + array[i][j] - std::abs(current_min_element - array[i][j])
            ) / 2;
        }
        std::cout << current_min_element << " ";
    }
    std::cout << std::endl;
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
    find_min_element_per_row(array, N, M);

    for (size_t i = 0; i < N; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}