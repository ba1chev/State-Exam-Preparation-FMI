// Напишете функция, която проверява дали един указател 
// сочи към даден адрес.
#include <iostream>

bool check_ptr(const int* ptr, const int& address) {
    return ptr == &address;
}

int main() {
    int number = 47;
    int random_number = 3;
    int* ptr = &random_number;

    std::cout << check_ptr(&number, number) << std::endl;
    std::cout << check_ptr(ptr, number) << std::endl;
    return 0;
}
