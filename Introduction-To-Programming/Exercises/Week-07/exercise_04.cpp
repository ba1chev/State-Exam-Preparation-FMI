// Да се състави програма, която установява дали целочисленият двумерен 
// масив А с размерност mxn съдържа отрицателен елемент.
#include <iostream>

bool has_negative_number(const int* const* array, 
    int count_of_rows, int count_of_cols) {
    if (count_of_rows < 0 || count_of_cols < 0 || !array) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    } 

    for (size_t i = 0; i < count_of_rows; i++) {
        for (size_t j = 0; j < count_of_cols; j++) {
            if (array[i][j] < 0) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int count_of_rows = 0;
    int count_of_cols = 0;
    std::cin >> count_of_rows >> count_of_cols;
    if (count_of_rows < 0 || count_of_cols < 0) {
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
    std::cout << has_negative_number(arrray, count_of_rows, count_of_cols) 
        << std::endl;

    for (size_t i = 0; i < count_of_rows; i++) {
        delete[] arrray[i];
        arrray[i] = nullptr;
    }
    delete[] arrray;
    arrray = nullptr;
    return 0;
}