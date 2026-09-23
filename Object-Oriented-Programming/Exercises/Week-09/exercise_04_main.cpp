// Да се напише шаблон на функция, която приема два параметъра от произволен тип и връща
// по-големия от двата елемента. Ако типът на параметрите е число с плаваща запетая, да се
// използва сравнение с достатъчно малка константа епсилон, в противен случай - не.
#include <iostream>
#include <cmath>

template <class T>
const T& maxElement(const T& left, const T& right) {
    if (left >= right) {
        return left;
    } else {
        return right;
    }
}

const float& maxElement(const float& left, const float& right) {
    if (std::abs(left - right) < 0.001f || left > right) {
        return left;
    }
    return right;
}

const double& maxElement(const double& left, const double& right) {
    if (std::abs(left - right) < 0.001 || left > right) {
        return left;
    }
    return right;
}

int main() {
    std::cout << maxElement(3, 7) << std::endl;
    std::cout << maxElement(2.5, 2.5000001) << std::endl;
    std::cout << maxElement(1.0f, 4.0f) << std::endl;

    return 0;
}