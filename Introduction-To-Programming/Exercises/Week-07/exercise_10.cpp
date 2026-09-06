// Да се състави програма, която установява дали реалният двумерен масив 
// А с размерност mxn съдържа елемента Х.
#include <iostream>

bool has_number(const float* const* array, 
    int count_of_rows, int count_of_cols, const float X) {
    if (count_of_rows < 0 || count_of_cols < 0 || !array) {
        std::cout << "Invalid function input" << std::endl;
        return false;
    } 

    for (size_t i = 0; i < count_of_rows; i++) {
        for (size_t j = 0; j < count_of_cols; j++) {
            if (std::abs(array[i][j] - X) < 0.001) {
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

    float** arrray = new float*[count_of_rows] {};
    for (size_t i = 0; i < count_of_rows; i++) {
        arrray[i] = new float[count_of_cols] {};
    }
    
    for (size_t i = 0; i < count_of_rows; i++) {
        for (size_t j = 0; j < count_of_cols; j++) {
            std::cin >> arrray[i][j];
        }
    }
    std::cout << has_number(arrray, count_of_rows, count_of_cols, 3.14)
        << std::endl;

    for (size_t i = 0; i < count_of_rows; i++) {
        delete[] arrray[i];
        arrray[i] = nullptr;
    }
    delete[] arrray;
    arrray = nullptr;
    return 0;
}