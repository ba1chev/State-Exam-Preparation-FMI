#include "exercise_04.h"

int main() {
    Matrix a(2, 3);
    Matrix b(2, 3);
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            a[i][j] = i + j;
            b[i][j] = 1;
        }
    }

    Matrix sum = a + b;
    Matrix diff = a - b;
    for (size_t i = 0; i < 2; i++) {
        for (size_t j = 0; j < 3; j++) {
            std::cout << sum[i][j] << " ";
        }
    }
    std::cout << std::endl;

    Matrix scaled = a * 2.0f;
    Matrix c(3, 2);
    Matrix product = a * c;
    std::cout << (a == a) << " " << (a != b) << " " << (bool)Matrix() << std::endl;

    return 0;
}
