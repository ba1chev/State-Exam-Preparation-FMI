// Да се състави функция, която по дадено цяло число n и 
// цифра k определя колко пъти в записа на числото се среща 
// цифрата k. Като се използва тази функция да се състави 
// програма, която чете от клавиатурата цифра k и 
// последователност от цели числа до въвеждане на отрицателно 
// число или 0 и отпечатва броя на тези от въведените числа, 
// които имат цифрата k в записа си поне два пъти.
#include <iostream>

int get_k_occurrences(int number, int k) {
    int counter = 0;
    while (number != 0) {
        if ((number % 10) == k) {
            counter += 1;
        }
        number /= 10;
    }

    return counter;
}

void count_numbers_with_k_twice() {
    int k = 0;
    int N = 0;
    int counter = 0;
    std::cin >> k;
    while (true) {
        std::cin >> N;
        if (N <= 0) {
            break;
        } 
        if (get_k_occurrences(N, k) >= 2) {
            counter += 1;
        }
    }
    std::cout << counter << std::endl;
}

int main() {
    count_numbers_with_k_twice();
    return 0;
}