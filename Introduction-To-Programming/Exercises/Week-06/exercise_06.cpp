// Дадени са сортирани във възходящ ред редици 
// а0,а1, а2, …, аk и b0, b1, …, bk. Да се състави програма, 
// която намира броя на равенствата от вида
// ai = bj (i =1, 2, .., k, j = 1,2, …, k, 0<=k<=100).
#include <iostream>

int main() {
    int array_1[7] = {1, 55, 120, 120, 450, 888, 9123};
    int array_2[7] = {7, 32, 91, 120, 120, 450, 888};
    int k = 7;

    int counter = 0;
    for (size_t i = 0; i < k; i++) {
        for (size_t j = 0; j < k; j++) {
            if (array_1[i] == array_2[j]) {
                counter += 1;
            }
        }
    }
    
    std::cout << counter << std::endl;
    return 0;
}
