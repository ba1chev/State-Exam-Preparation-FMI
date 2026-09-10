// Да се напише рекурсивна функция, която установява, 
// дали в записа на естественото число n се съдържа цифрата k.
#include <iostream>

bool contains_k(int number, const int k) {
    if (!number) {
        return false;
    }
    if ((number % 10) == k) {
        return true;
    }
    return contains_k(number / 10, k);
}

int main() {
    std::cout << contains_k(1234, 2) << std::endl;
    std::cout << contains_k(1234, 5) << std::endl;
    return 0;
}