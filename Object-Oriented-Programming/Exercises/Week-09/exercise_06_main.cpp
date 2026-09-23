#include "exercise_06.hpp"
#include <string>

int main() {
    Optional<int> empty;
    Optional<int> full(42);

    std::cout << empty.hasValue() << " " << full.hasValue() << std::endl;
    std::cout << full.value() << " " << *full << std::endl;
    std::cout << empty.valueOr(-1) << " " << full.valueOr(-1) << std::endl;
    std::cout << (bool)empty << " " << (bool)full << std::endl;

    full.reset();
    std::cout << full.hasValue() << std::endl;

    Optional<std::string> word("hello");
    Optional<std::string> copy = word;
    std::cout << *copy << std::endl;

    return 0;
}
