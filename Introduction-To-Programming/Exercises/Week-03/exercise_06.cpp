// Нека са дадени числата a и b. 
// Да се напише булев израз, който има стойност истина, ако а е по-малко от b.
#include <iostream>

int main() {
    int a, b = 0;
    std::cin >> a >> b;
    bool predicate = a < b;
    std::cout << predicate << std::endl;
    return 0;
}
