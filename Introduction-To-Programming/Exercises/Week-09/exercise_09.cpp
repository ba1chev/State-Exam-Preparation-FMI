// Напишете функция, която приема референция 
// към пойнтър и му променя стойността на nullptr.
#include <iostream>

void set_to_nullptr(int*& ref_ptr) {
    ref_ptr = nullptr;
}

int main() {
    int number = 3;
    int* ptr = &number;
    std::cout << ptr << std::endl;

    set_to_nullptr(ptr);
    std::cout << ptr << std::endl;
    return 0;
}