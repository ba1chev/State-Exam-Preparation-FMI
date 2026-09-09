// Напишете функция, която приема пойнтер към масив от int и 
// връща sizeof(arr)/sizeof(arr[0]). Това размерът на масива ли е? 
// Ако не - какво е?
#include <iostream>

int get_element_count(const int* array) {
    if (!array) {
        std::cout << "Invalid function input" << std::endl;
        return -1;
    }

    return sizeof(array) / sizeof(array[0]);
}

int main() {
    int arrray[3] = {1, 2, 3};
    std::cout << get_element_count(arrray) << std::endl;
    return 0;
}