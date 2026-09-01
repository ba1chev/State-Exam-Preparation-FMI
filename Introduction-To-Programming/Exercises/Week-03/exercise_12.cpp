// Нека са дадени положителните естествени 
// числа a, b и c. Да се напише булев израз, 
// който има стойност истина, ако 
// квадратното уравнение ax2 + bx + c = 0 
// има два реални, различни корена.
#include <iostream>

int main() {
    int a, b, c = 0;
    std::cin >> a >> b >> c;
    bool predicate = (b * b - 4 * a * c) > 0;
    std::cout << predicate << std::endl;
    return 0;
}
