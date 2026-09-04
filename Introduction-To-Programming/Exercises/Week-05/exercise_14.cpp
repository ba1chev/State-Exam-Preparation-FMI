// Дадена е редица от N на брой цели числа. 
// Намерете НОД и НОК на всички числа.
#include <iostream>

int get_max(int left, int right) {
    return (left + right + std::abs(left - right)) / 2;
}

int nod(const int* numbers, int size) {
    if (!numbers || size < 0) {
        std::cout << "Invalid input" << std::endl;
        return -1;
    }

    int max_number = INT_MIN;
    for (size_t i = 0; i < size; i++) {
        max_number = get_max(max_number, numbers[i]);
    }
    
    int result = 1;
    for (size_t i = 2; i <= max_number; i++) {
        bool is_candidate = true;

        for (size_t j = 0; j < size; j++) {
            if (numbers[j] % i != 0) {
                is_candidate = false;
                break;
            }
        }
        
        if (is_candidate) {
            result = get_max(result, i);
        }
    }
    
    return result;
}

int nok(const int* numbers, int size) {
    if (!numbers || size < 0) {
        std::cout << "Invalid input" << std::endl;
        return -1;
    }

    int result = numbers[0];
    for (size_t i = 1; i < size; i++) {
        int a = result;
        int b = numbers[i];
        int temp_a = a, temp_b = b;
        while (temp_b != 0) {
            int t = temp_b;
            temp_b = temp_a % temp_b;
            temp_a = t;
        }
        result = (a / temp_a) * b;
    }

    return result;
}

int main() {
    int numbers[5] = {32, 4, 16, 6, 50};
    std::cout << "NOD: "<< nod(numbers, 5) << std::endl;
    std::cout << "NOK: "<< nok(numbers, 5) << std::endl;
    return 0;
}