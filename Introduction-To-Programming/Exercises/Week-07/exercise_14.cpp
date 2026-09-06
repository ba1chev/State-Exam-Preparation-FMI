// Даден е двумерен масив с размери mxn, образуван от 1 и 0. 
// Област наричаме група съседни единици. Съседни на дадена 
// клетка са тези отгоре, отдолу, отляво и отдясно. Да се изведе броя области в масива.
// Ограничения: 2 <= n, m <= 100
#include <iostream>

void mark_region(int** array,
    int count_of_rows, int count_of_cols, int i, int j) {
    if (i < 0 || j < 0 || i >= count_of_rows || j >= count_of_cols || array[i][j] == 2 || array[i][j] == 0) {
        return;
    }
    
    array[i][j] = 2;
    mark_region(array, count_of_rows, count_of_cols, i, j + 1);
    mark_region(array, count_of_rows, count_of_cols, i + 1, j);
    mark_region(array, count_of_rows, count_of_cols, i - 1, j);
    mark_region(array, count_of_rows, count_of_cols, i, j - 1);
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
            if (arrray[i][j] != 0 && arrray[i][j] != 1) {
                for (size_t i = 0; i < count_of_rows; i++) {
                    delete[] arrray[i];
                    arrray[i] = nullptr;
                }
                delete[] arrray;
                arrray = nullptr;

                std::cout << "Invalid input" << std::endl;
                return 1;
            }
        }
    }

    int counter = 0;
    for (size_t i = 0; i < count_of_rows; i++) {
        for (size_t j = 0; j < count_of_cols; j++) {
            if (arrray[i][j] == 1) {
                counter += 1;
                mark_region(
                    arrray, count_of_rows, count_of_cols, i, j
                );
            }
        }
    }
    std::cout << counter << std::endl;

    for (size_t i = 0; i < count_of_rows; i++) {
        delete[] arrray[i];
        arrray[i] = nullptr;
    }
    delete[] arrray;
    arrray = nullptr;
    return 0;
}