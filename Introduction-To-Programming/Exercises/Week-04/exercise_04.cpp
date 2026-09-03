// Да се състави програма, която по въведено естествено число N намира и 
// отпечатва всички тройки естествени числа a, b и c, не по-големи от N, 
// които могат да бъдат страни на правоъгълен триъгълник.
#include <iostream>

int main() {
    int N = 0;
    std::cin >> N;

    for (size_t i = 1; i <= N; i++) {
        for (size_t j = i; j <= N; j++) {
            for (size_t k = j; k <= N; k++) {
                bool pred_1 = (i + j > k) && (k + j > i) && (i + k > j);
                bool pred_2 = ((i * i + j * j) == k * k) ||
                    ((k * k + j * j) == i * i) || ((i * i + k * k) == j * j);
                if (pred_1 && pred_2) {
                    std::cout << i << " " << j << " " << k << std::endl; 
                }
            }
        }
    }
    
    return 0;
}