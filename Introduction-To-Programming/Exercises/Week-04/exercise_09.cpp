// Напишете програма, която приема естествено число N (N < 10) и 
// булева стойност M. Програмата изписва pattern стрелка, където N е 
// височината на триъгълника, а M казва накъде сочи стрелката 
// (true - нагоре, а false - надолу).
#include <iostream>

int main() {
    int N = 0;
    bool M = 0;
    std::cin >> N >> M;

    int count_of_rows = N;
    int count_of_cols = 1;
    for (size_t i = 0; i < N - 1; i++) {
        count_of_cols += 2;
    }
    int left_ptr = count_of_cols / 2;
    int right_ptr = left_ptr + 1;
    
    if (M) {
        for (size_t i = 0; i < count_of_rows; i++) {
            for (size_t j = 0; j < left_ptr; j++) {
                std::cout << "+";
            }

            for (size_t j = left_ptr; j < right_ptr; j++) {
                std::cout << "#";
            }
            
            for (size_t j = right_ptr; j < count_of_cols; j++) {
                std::cout << "+";
            }

            left_ptr -= 1;
            right_ptr += 1;
            std::cout << std::endl;
        }
        for (size_t i = 0; i < count_of_rows; i++) {
            for (size_t j = 0; j < count_of_cols; j++) {
                if (j == (count_of_cols / 2)) {
                    std::cout << "#";
                } else {
                    std::cout << "+";
                }
            }   
            std::cout << std::endl;
        }
    } else {
        left_ptr = 0;
        right_ptr = count_of_cols;

        for (size_t i = 0; i < count_of_rows; i++) {
            for (size_t j = 0; j < count_of_cols; j++) {
                if (j == (count_of_cols / 2)) {
                    std::cout << "#";
                } else {
                    std::cout << "+";
                }
            }   
            std::cout << std::endl;
        }
        for (size_t i = 0; i < count_of_rows; i++) {
            for (size_t j = 0; j < left_ptr; j++) {
                std::cout << "+";
            }

            for (size_t j = left_ptr; j < right_ptr; j++) {
                std::cout << "#";
            }
            
            for (size_t j = right_ptr; j < count_of_cols; j++) {
                std::cout << "+";
            }

            left_ptr += 1;
            right_ptr -= 1;
            std::cout << std::endl;
        }
    }

    return 0;
}