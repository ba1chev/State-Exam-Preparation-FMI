// Напишете функция, която разменя стойностите на две променливи.
#include <iostream>

void swap(int& left, int& right) {
    left ^= right;
    right ^= left;
    left ^= right;
}

int main() {
    int left = 3;
    int right = 2;
    std::cout << left << " " << right << std::endl;
    
    swap(left, right);
    std::cout << left << " " << right << std::endl;
    return 0;
}