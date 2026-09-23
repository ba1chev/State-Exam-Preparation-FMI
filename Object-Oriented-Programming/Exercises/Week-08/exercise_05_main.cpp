#include "exercise_05.h"

int main() {
    Color a(200, 100, 50);
    Color b(100, 100, 100);

    std::cout << (a + b) << std::endl;
    std::cout << (a - b) << std::endl;
    std::cout << (a * 0.5f) << std::endl;
    std::cout << (a * b) << std::endl;
    std::cout << ~a << std::endl;

    std::cout << (a == a) << " " << (a != b) << " " << (bool)Color(0, 0, 0, 0) << std::endl;

    return 0;
}
