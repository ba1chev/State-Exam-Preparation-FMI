// Напишете програма, която създава променлива от тип int и референция към 
// същата променлива, а после променя стойността на променливата, използвайки 
// референцията. 
#include <iostream>

int main() {
    int number = 47;
    int& number_ref = number;
    number_ref += 1;
    std::cout << number << std::endl;
    return 0;
}