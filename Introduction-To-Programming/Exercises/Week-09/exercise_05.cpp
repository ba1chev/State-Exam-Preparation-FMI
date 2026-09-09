// Напишете програма, която въвежда масив от 
// N числа и изведете адреса на най-голямото от тях.
#include <iostream>

int main() {
    int N = 0;
    std::cin >> N;
    int* array = new int[N]{};
    
    int current_number = 0;
    int max_number = INT_MIN;
    int* address = nullptr;
    for (size_t i = 0; i < N; i++) {
        std::cin >> array[i];
        int prev_max_number = max_number;
        max_number = (
            max_number + array[i] + std::abs(max_number - array[i])
        ) / 2;

        if (prev_max_number != max_number) {
            address = &array[i];
        }
    }
 
    std::cout << address << std::endl;
    delete[] array;
    array = nullptr;
    return 0;
}