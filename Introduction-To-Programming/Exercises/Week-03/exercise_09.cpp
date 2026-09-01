// Нека са дадени две естествени числа a и b. 
// Да се напише булев израз, който има стойност истина, 
// ако a повдигнато на квадрат дава b.
#include <iostream>

int main() {
    int a, b = 0;
    std::cin >> a >> b;
    bool predicate = ((a * a) == b);
    std::cout << predicate << std::endl;
    return 0;
}