// Дадена е правоъгълна матрица А с размери MxN, съставена от цели числа. 
// Дадени са числата P и Q (0<P<N, 0<Q<M). Намерете най-голямата сума, съставена от 
// подматрица на А с размери PxQ.
#include <iostream>

int get_sum_of_sliding(const int* const* array, int starting_i, int starting_j, 
    int i_blocks, int j_blocks) {
    if (!array || starting_i < 0 || starting_j < 0 || 
        i_blocks < 0 || j_blocks < 0) {
        std::cout << "Invalid function input" << std::endl;
        return 0;
    }

    int result_sum = 0;
    for (size_t i = starting_i; i < starting_i + i_blocks; i++) {
        for (size_t j = starting_j; j < starting_j + j_blocks; j++) {
            result_sum += array[i][j];
        }
    }

    return result_sum;
}

int main() {
    int count_of_rows = 0;
    int count_of_cols = 0;
    std::cin >> count_of_rows >> count_of_cols;
    if (count_of_rows < 2 || count_of_rows > 100 ||
        count_of_cols < 2 || count_of_cols > 100) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** arrray = new int*[count_of_rows] {};
    for (size_t i = 0; i < count_of_rows; i++) {
        arrray[i] = new int[count_of_cols] {};
    }
    
    for (size_t i = 0; i < count_of_rows; i++) {
        for (size_t j = 0; j < count_of_cols; j++) {
            std::cin >> arrray[i][j];
        }
    }

    int P = 0;
    int Q = 0;
    std::cin >> P >> Q;
    int max_sum = INT_MIN;
    for (size_t i = 0; i < count_of_rows; i++) {
        for (size_t j = 0; j < count_of_cols; j++) {
            if (i + Q <= count_of_rows && j + P <= count_of_cols) {
                int current_sub_sum = get_sum_of_sliding(arrray, i, j, Q, P);
                max_sum = (max_sum + current_sub_sum +
                    std::abs(max_sum - current_sub_sum)) / 2;
            }
        }
    }
    std::cout << max_sum << std::endl;

    for (size_t i = 0; i < count_of_rows; i++) {
        delete[] arrray[i];
        arrray[i] = nullptr;
    }
    delete[] arrray;
    arrray = nullptr;
    return 0;
}