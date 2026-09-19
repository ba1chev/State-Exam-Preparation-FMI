#include "exercise_05.h"

int main() {
    MultiSet set(5, 3);

    set.addNumber(1);
    set.addNumber(1);
    set.addNumber(1);
    set.addNumber(3);
    set.addNumber(5);
    set.addNumber(5);

    std::cout << set << std::endl;
    std::cout << "Count of 1: " << set.getCount(1) << std::endl;
    std::cout << "Count of 5: " << set.getCount(5) << std::endl;
    std::cout << "Has 3: " << set.hasNumber(3) << std::endl;
    std::cout << "Has 4: " << set.hasNumber(4) << std::endl;

    std::cout << "Memory: ";
    set.printMemory();

    MultiSet other(5, 3);
    other.addNumber(1);
    other.addNumber(3);
    other.addNumber(3);
    other.addNumber(5);

    std::cout << "Union: " << (set | other) << std::endl;
    std::cout << "Intersection: " << (set & other) << std::endl;

    MultiSet comp = set;
    comp.complement();
    std::cout << "Complement: " << comp << std::endl;

    set.serialize("multiset.bin");
    MultiSet loaded(5, 3);
    loaded.deserialize("multiset.bin");
    std::cout << "Deserialized: " << loaded << std::endl;

    return 0;
}
