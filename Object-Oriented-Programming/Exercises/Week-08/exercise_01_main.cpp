#include "exercise_01.h"

int main() {
    MulString first = "ABCDEFABJ";
    MulString second = "BCDGHJ";

    std::cout << first * 3 << std::endl;
    std::cout << 2 * second << std::endl;
    std::cout << (first % second) << std::endl;
    std::cout << (first != second) << std::endl;

    first *= 2;
    std::cout << first << std::endl;
    second %= "XYZ";
    std::cout << second << std::endl;

    return 0;
}
