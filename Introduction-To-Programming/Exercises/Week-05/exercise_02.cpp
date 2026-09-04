// Да се напише функция isEven(const int num), 
// която връща дали дадено число е четно или не.
#include <iostream>

bool isEven(const int num) {
    return !(num & 1);
}

int main() {
    std::cout << isEven(1) << " " << isEven(20) << std::endl;
    return 0;
}