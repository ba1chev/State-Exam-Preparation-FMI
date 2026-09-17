#include "exercise_01.h"

int main() {
    BitSet set(100);
    set.addNumber(3);
    set.addNumber(7);
    set.addNumber(42);
    set.addNumber(100);
    set.print();

    std::cout << set.hasNumber(42) << std::endl;
    std::cout << set.hasNumber(41) << std::endl;

    set.removeNumber(7);
    set.print();
    std::cout << set.hasNumber(7) << std::endl;

    BitSet copy = set;
    copy.addNumber(200);
    copy.print();
    set.print();

    BitSet moved = std::move(copy);
    moved.print();

    return 0;
}