// Нека е дадено естествено число а. Да се напише булев израз, 
// който има стойност истина, ако а се дели на 2.
#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;
    bool predicate = number % 2 == 0;
    std::cout << predicate << std::endl;
    return 0;
}
