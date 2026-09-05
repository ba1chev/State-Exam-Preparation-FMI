// Да се състави програма, която пресмята сумата: 
// a0b0 + a1b1 + … + an-1bn-1, където (а0, а1, …, аn-1) и (b0, b1, …, bn-1) 
// са два дадени едномерни масива от числен тип (1 < n < 50) .
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    if (n < 0 || n >= 50) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int array_1[50]{};
    int array_2[50]{};
    int result_sum = 0;

    for (size_t i = 0; i < n; i++) {
        std::cin >> array_1[i];
    }
    for (size_t i = 0; i < n; i++) {
        std::cin >> array_2[i];
    }
    for (size_t i = 0; i < n; i++) {
        result_sum += array_1[i] * array_2[i];
    }
    
    std::cout << result_sum << std::endl;
    return 0;
}