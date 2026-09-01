// Нека са дадени две естествени числа a и b. Да се напише булев израз, 
// който има стойност истина, ако а дели b без остатък.
#include <iostream>

int main() {
    int a, b = 0;
    std::cin >> a >> b;
    bool predicate = a % b == 0;
    std::cout << predicate << std::endl;
    return 0;
}
