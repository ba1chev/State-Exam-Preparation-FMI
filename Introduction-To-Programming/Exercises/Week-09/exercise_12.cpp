// Напишете функция, която приема пойнтер 
// към масив от unsigned long long и размера му и връща 
// стойността на последния елемент без да се използва оператора [].
#include <iostream>

unsigned long long get_last_number(unsigned long long* array, int size) {
    if (!array || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return -1;
    }

    return *(array + size - 1);
}

int main() {
    unsigned long long array[3] = {1, 2, 3};
    std::cout << get_last_number(array, 3) << std::endl;
    return 0;
}