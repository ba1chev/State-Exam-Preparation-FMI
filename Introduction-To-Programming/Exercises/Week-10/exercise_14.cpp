// Дадена е матрица А с размер Nx2. Сортирайте редовете й в нарастващ ред по първия елемент. 
// Ако първите елементи са равни, по вторите. Изведете я.
#include <iostream>

bool compare_rows(const int* row_1, const int* row_2) {
    if (!row_1 || !row_2) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    }

    if (row_1[0] == row_2[0]) {
        return row_1[1] > row_2[1];
    }
    return row_1[0] > row_2[0];
}

void sort_array(int** array, int N) {
    if (!array || N < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < N - 1; i++) {
        for (size_t j = 0; j < N - i - 1; j++) {
            if (compare_rows(array[j], array[j + 1])) {
                int* temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
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

    int** array = new int*[N]{nullptr};
    for (size_t i = 0; i < N; i++) {
        array[i] = new int[2]{};
    }
    
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < 2; j++) {
            std::cin >> array[i][j];
        }
    }

    std::cout << std::endl;
    sort_array(array, N);
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < 2; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    for (size_t i = 0; i < N; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}