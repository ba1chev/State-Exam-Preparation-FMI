// Да се напише програма, която въвежда 
// две неотрицателни числа и изчислява с 
// колко порядъка се различават.
#include <iostream>
#include <cstdlib>

int count_of_digits(int number) {
    if (number == 0) {
        return 1;
    }

    int result = 0;
    while (number != 0) {
        result += 1;
        number /= 10;
    }

    return result;
}

int main() {
    int number_1, number_2 = 0;
    std::cin >> number_1 >> number_2;

    int count_1 = count_of_digits(number_1);
    int count_2 = count_of_digits(number_2);
    std::cout << std::abs(count_1 - count_2) << std::endl;

    return 0;
}