// Да се състави програма, която въвежда n реални числа и 
// извежда минималното и максималното от тях (0 < n < 50).
#include <iostream>
#include <climits>

int get_max(const int left, const int right) {
    return (left + right + std::abs(left - right)) / 2;
}

int get_min(const int left, const int right) {
    return (left + right - std::abs(left - right)) / 2;
}

int main() {
    int n = 0;
    std::cin >> n;
    if (n < 0 || n >= 50) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int array[50]{};
    int max_element = INT_MIN;
    int min_element = INT_MAX;
    for (size_t i = 0; i < n; i++) {
        std::cin >> array[i];
        max_element = get_max(max_element, array[i]);
        min_element = get_min(min_element, array[i]);
    }
    
    std::cout << min_element << " " << max_element << std::endl;
    return 0;
}