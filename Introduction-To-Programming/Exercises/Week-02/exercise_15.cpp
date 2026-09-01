// Задача Да се въведе положително число а. Да се изведе:
// лицето и обиколката на квадрат със страна а;
// дължината на окръжност с радиус а;
// лицето и обиколката на равностранен триъгълник със страна а.
// Приемаме, че sqrt(3) = 1.73.
#include <iostream>

int main() {
    int a = 0;
    const float pi = 3.14;
    std::cin >> a;

    std::cout << "square: p=" << 4 * a << " s=" << a * a << std::endl;
    std::cout << "circle: p=" << 2 * pi * a << std::endl;
    std::cout << "triangle: p=" << 3 * a << " s=" << (a * a * 1.73f) / 4.0f << std::endl;
    return 0;
}