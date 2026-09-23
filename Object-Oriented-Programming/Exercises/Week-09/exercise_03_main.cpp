// Да се напише шаблон на функция, която разменя стойностите на
// две променливи от произволен тип (променливите трябва да бъдат от един и
// същи тип).
#include <iostream>
#include <string>

template <class T>
void swap(T& left, T& right) {
    T temp = left;
    left = right;
    right = temp;
}

int main() {
    int left = 0;
    int right = 1;
    swap<int>(left, right);
    std::cout << left << " " << right << std::endl;

    std::string first = "hello";
    std::string second = "world";
    swap(first, second);
    std::cout << first << " " << second << std::endl;

    return 0;
}