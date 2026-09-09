// Напишете функция, която взима два пойнтера - 
// единият към int, а другият към пойнтер към int, и 
// казва дали вторият пойнтер сочи към първия.
#include <iostream>

bool check_ptr(int* left_ptr, int** right_ptr) {
    return left_ptr == (*right_ptr);
}

int main() {
    int number = 3;
    int* left_ptr = &number;
    int** right_ptr = &left_ptr;

    std::cout << check_ptr(left_ptr, right_ptr) << std::endl;
    return 0;
}