// Дадена е квадратна мрежа от клетки, всяка от които е празна или запълнена. 
// Запълнените клетки, които са свързани, т.е. имат съседни в хоризонтално, 
// вертикално или диагонално направление, образуват област. Да се напише програма, 
// която намира броя на областите и размера (в брой клетки) на всяка област.
#include <iostream>

int get_count_of_regions(int array[][100], int rows_count, int cols_count, int i, int j) {
    if (!array || rows_count < 0 || cols_count < 0 ||
        i >= rows_count || j >= cols_count || i < 0 || j < 0 || array[i][j] == 0) {
        return 0;
    }

    array[i][j] = 0;
    int size = 1;

    size += get_count_of_regions(array, rows_count, cols_count, i + 1, j);
    size += get_count_of_regions(array, rows_count, cols_count, i, j + 1);
    size += get_count_of_regions(array, rows_count, cols_count, i - 1, j);
    size += get_count_of_regions(array, rows_count, cols_count, i, j - 1);
    size += get_count_of_regions(array, rows_count, cols_count, i - 1, j + 1);
    size += get_count_of_regions(array, rows_count, cols_count, i + 1, j - 1);
    size += get_count_of_regions(array, rows_count, cols_count, i + 1, j + 1);
    size += get_count_of_regions(array, rows_count, cols_count, i - 1, j - 1);

    return size;
}

int main() {
    int rows_count = 3;
    int cols_count = 4;
    int data[100][100] = {
        {1, 1, 0, 0},
        {1, 1, 0, 1},
        {0, 0, 0, 1}
    };

    int counter = 0;
    for (size_t i = 0; i < rows_count; i++) {
        for (size_t j = 0; j < cols_count; j++) {
            if (data[i][j] == 1) {
                int current_size = get_count_of_regions(
                    data, rows_count, cols_count, i, j
                );

                std::cout << "Region" << counter << " with size: " <<
                    current_size << std::endl;
                counter += 1;
            }
        }   
    }
    
    std::cout << "The count of the regions is: " << counter << std::endl;
    return 0;
}