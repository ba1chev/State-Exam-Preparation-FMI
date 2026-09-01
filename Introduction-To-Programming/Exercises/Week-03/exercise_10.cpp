// Нека са дадени три естествени числа a, b и c. 
// Да се напише булев израз, който проверява дали дали 
// a и b са сравними относно c. 
// (a и b се наричат делими по модул ако имат 
// равни остатъци при делене с c)
#include <iostream>

int main() {
    int a, b, c = 0;
    std::cin >> a >> b >> c;
    bool predicate = (a % c) == (b % c);
    std::cout << predicate << std::endl;
    return 0;
}