#include "exercise_02.h"

int main() {
    float first[] = { 1.0f, 2.0f, 3.0f };
    float second[] = { 4.0f, 5.0f };

    Vector a(first, 3);
    Vector b(second, 2);

    Vector sum = a + b;
    Vector diff = a - b;
    for (size_t i = 0; i < sum.getSize(); i++) {
        std::cout << sum[i] << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < diff.getSize(); i++) {
        std::cout << diff[i] << " ";
    }
    std::cout << std::endl;

    Vector scaled = a * 2.0f;
    for (size_t i = 0; i < scaled.getSize(); i++) {
        std::cout << scaled[i] << " ";
    }
    std::cout << std::endl;

    std::cout << (a == a) << " " << (a != b) << " " << (a > b) << std::endl;

    return 0;
}
