// Да се състави програма, която прочита две реални числа 
// r и φ, които са съответно модул и аргумент (в радиани) 
// на комплексно число, представено в тригонометричен вид 
// z=r(cos⁡(φ)+isin(φ). Да се изведат реалната и 
// имагинерната част a и b на комплексното число в 
// алгебричен вид z=a+bi с точност до третата цифра след десетичната запетая.
#include <iostream>

int main() {
    float r = 0.0;
    float radian = 0.0;
    const float pi = 3.14159265359f;
    std::cin >> r >> radian;

    float sin_fi_angle = (16 * radian * (pi - radian)) / 
        (5 * pi * pi - 4 * radian * (pi - radian));
    float cos_fi_angle = (pi * pi - 4 * radian * radian) /
        (pi * pi + radian * radian);
    
    float a = r * cos_fi_angle;
    float b = r * sin_fi_angle;
    std::cout << a << " " << b << std::endl; 
    return 0;
}