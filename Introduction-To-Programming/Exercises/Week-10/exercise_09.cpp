// Да се състави програма, която намира броя на отрицателните елементи във 
// всеки ред на двумерен масив.
#include <iostream>

void find_negative_element_per_row(const int* const* array, int N, int M) {
    if (!array || N < 0 || M < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < N; i++) {
        if (!array[i]) {
            std::cout << "Invalid function input" << std::endl;
            return;
        }

        int current_counter = 0;
        for (size_t j = 0; j < M; j++) {
            if (array[i][j] < 0) {
                current_counter += 1;
            }
        }
        std::cout << current_counter << " ";
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
    find_negative_element_per_row(array, N, M);

    for (size_t i = 0; i < N; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}