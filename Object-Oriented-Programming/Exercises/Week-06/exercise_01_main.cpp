#include "exercise_01.h"

int main() {
    BitSet set(100);
    set.addNumber(3);
    set.addNumber(7);
    set.addNumber(42);
    set.addNumber(100);
    set.print(); // {3 7 42 100 }

    std::cout << set.hasNumber(42) << std::endl; // 1
    std::cout << set.hasNumber(41) << std::endl; // 0

    set.removeNumber(7);
    set.print(); // {3 42 100 }
    std::cout << set.hasNumber(7) << std::endl; // 0

    BitSet copy = set;
    copy.addNumber(200);
    copy.print(); // {3 42 100 200 }
    set.print();  // {3 42 100 }

    BitSet moved = std::move(copy);
    moved.print(); // {3 42 100 200 }

    return 0;
}