// Напишете функция, която приема референция към 
// пойнтер към int и принтира адреса на пойнтера, адреса в 
// пойнтера и стойността на адреса в пойнтера.
#include <iostream>

void print_pointer_info(int*& ref_ptr) {
    std::cout << &ref_ptr << " ";
    std::cout << ref_ptr << " ";
    std::cout << *ref_ptr << std::endl;
}

int main() {
    int number = 47;
    int* ptr = &number;
    print_pointer_info(ptr);
    return 0; 
}