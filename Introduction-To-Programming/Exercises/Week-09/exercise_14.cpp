// Напишете функция, която взима референция към float и 
// връща стойността на цялото число, образувано от прочитането на 
// същата памет, която ползва float-а, като int.
#include <iostream>

int float_bits_as_int(float& number) {
    int* ptr = reinterpret_cast<int*>(&number);
    return *ptr;
}

int main() {
    float number = 3.14f;
    std::cout << float_bits_as_int(number) << std::endl;
    return 0;
}