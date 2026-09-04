// Напишете функция ascii(const char symbol), 
// която връща като резултат ascii номера на 
// параметъра symbol.
#include <iostream>

int ascii(const char symbol) {
    return (int)symbol;
}

int main() {
    std::cout << ascii('A') << " " << ascii('a') << std::endl;
    return 0;
}