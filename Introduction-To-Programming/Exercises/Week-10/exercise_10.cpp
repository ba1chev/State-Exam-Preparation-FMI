// Да се състави програма, която намира и извежда сумата от всеки ред на 
// двумерен целочислен масив. Програмата получава първо число N - броя 
// редове на двумерния масив, а след това получава N на брой числа - 
// а1, а2, ..., аN, които показват броя на елементите масивите, за които 
// дължината на ред k е аk.
#include <iostream>

void find_sum_per_row(const int* const* array, int N) {
    if (!array || N < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int current_row_sum = 0;
    for (size_t i = 0; i < N; i++) {
        if (!array[i]) {
            std::cout << "Invalid function input" << std::endl;
            return;
        }

        int current_row_size = array[i][0];
        for (size_t j = 1; j < current_row_size + 1; j++) {
            current_row_sum += array[i][j];
        }
        std::cout << current_row_sum << " ";
        current_row_sum = 0;
    }
    std::cout << std::endl;
}

int main() {
    int N = 0;
    std::cin >> N;
    if (N < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** array = new int*[N]{nullptr};
    int current_row_size = 0;
    for (size_t i = 0; i < N; i++) {
        std::cin >> current_row_size;
        array[i] = new int[current_row_size + 1]{};
        array[i][0] = current_row_size;
    }
    
    for (size_t i = 0; i < N; i++) {
        current_row_size = array[i][0];
        for (size_t j = 1; j < current_row_size + 1; j++) {
            std::cin >> array[i][j];
        }
    }
    find_sum_per_row(array, N);

    for (size_t i = 0; i < N; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}