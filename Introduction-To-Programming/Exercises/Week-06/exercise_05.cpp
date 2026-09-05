// Да се състави програма, която намира максималния елемент в 
// даден масив, а също и неговия пореден номер.
#include <iostream>
#include <climits>

void find_max_number_position(const int* array, int size) {
    if (!array || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int max_number = INT_MIN;
    int number_position = 0;
    for (size_t i = 0; i < size; i++) {
        int prev_max_number = max_number;
        max_number = (max_number + array[i] + std::abs(max_number - array[i])) / 2;
        if (max_number != prev_max_number) {
            number_position = i;
        }
    }
    
    std::cout << "Max number is: " << max_number << ", and it position in the array is: " <<
        number_position << std::endl;
}

int main() {
    int n = 0;
    std::cin >> n;

    int* array = new int[n]{};
    for (size_t i = 0; i < n; i++) {
        std::cin >> array[i];
    }    
    find_max_number_position(array, n);

    delete[] array;
    array = nullptr;
    return 0;
}