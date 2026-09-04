// Напишете функция abs(const int num), 
// която връща като резултат абсолютната стойност на числото num.
#include <iostream>

int abs(const int num) {
    if (num < 0) {
        return -1 * num;
    }
    return num;
}

int main() {
    std::cout << abs(-1) << " " << abs(1) << std::endl;
    return 0;
}