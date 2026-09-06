// Дадена е квадратна матрица Х с размерност kxk и цяло число s. 
// Да се състави програма, която намира сумата от онези елементи на матрицата Х, 
// сборът от индексите на които е равен на s.
#include <iostream>

void find_sum_sum_of(const int* const* array, int k, int s) {
    if (!array || k < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int result_sum = 0;
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < k; j++) {
            if (i + j == s) {
                result_sum += array[i][j];
            }
        }
    }
    std::cout << result_sum << std::endl;
}

int main() {
    int k = 0;
    std::cin >> k;
    if (k < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** array = new int*[k]{};
    for (size_t i = 0; i < k; i++) {
        array[i] = new int[k]{};
    }
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < k; j++) {
            std::cin >> array[i][j];
        }
    }
    int s = 0;
    std::cin >> s;
    find_sum_sum_of(array, k, s);

    for (size_t i = 0; i < k; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}