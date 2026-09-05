// Да се състави програма, която извежда сумата от положителните и 
// броя на отрицателните елементи на редицата от реални числа 
// а1, а2, …, аn (0 < n < 24).
#include <iostream>

int main() {
    int n = 0;
    int numbers[24]{};
    std::cin >> n;
    if (n < 0 || n > 24) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int sum_positive = 0;
    int count_negative = 0;
    for (size_t i = 0; i < n; i++) {
        std::cin >> numbers[i];
        if (numbers[i] > 0) {
            sum_positive += numbers[i];
        } else if (numbers[i] < 0) {
            count_negative += 1;
        }
    }

    std::cout << sum_positive << " " << count_negative << std::endl;
    return 0;
}