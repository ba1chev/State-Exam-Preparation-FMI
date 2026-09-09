// Да се състави програма, която въвежда n реални числа и извежда 
// минималното и максималното от тях (0 < n < INT_MAX).
#include <iostream>

float get_min(const float* array, int size) {
    if (!array || size < 1) {
        std::cout << "Invalid function input" << std::endl;
        return -1;
    }

    float min_number = array[0];
    for (size_t i = 1; i < size; i++) {
        min_number = (min_number + array[i] - std::abs(min_number - array[i])) / 2;
    }
    
    return min_number;
}

float get_max(const float* array, int size) {
    if (!array || size < 1) {
        std::cout << "Invalid function input" << std::endl;
        return -1;
    }

    float max_number = array[0];
    for (size_t i = 1; i < size; i++) {
        max_number = (max_number + array[i] + std::abs(max_number - array[i])) / 2;
    }
    
    return max_number;
}

int main() {
    int n = 0;
    std::cin >> n;

    float* numbers = new float[n]{};
    for (size_t i = 0; i < n; i++) {
        std::cin >> numbers[i];
    }
    
    std::cout << get_max(numbers, n) << " " << get_min(numbers, n) << std::endl;
    delete[] numbers;
    numbers = nullptr;
    return 0;
}
