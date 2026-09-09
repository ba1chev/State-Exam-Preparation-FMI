// Напишете програма, която извежда елементите на 
// масив без оператора [].
#include <iostream>

int main() {
    int array[3] = {1, 2, 3};
    int* ptr = array;
    for (size_t i = 0; i < 3; i++) {
        std::cout << *ptr << " ";
        ptr += 1;
    }
    
    std::cout << std::endl;
    return 0;
}