#include "exercise_03.hpp"

int main() {
    WeakCache<int, int> cache(3);
    cache.addValueBy(1, 100);
    cache.addValueBy(2, 200);
    cache.addValueBy(3, 300);

    std::cout << cache.getValueBy(1) << " "
        << cache.getValueBy(2) << " "
        << cache.getValueBy(3) << std::endl;
    std::cout << cache.getCountOfUsedUnits() << " "
        << cache.getCountOfUnusedUnits() << std::endl;

    try {
        cache.addValueBy(4, 400);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    WeakCache<int, int> copy = cache;
    std::cout << copy.getValueBy(1) << " "
        << copy.getCountOfUsedUnits() << std::endl;

    WeakCache<int, int> moved = std::move(copy);
    std::cout << moved.getValueBy(2) << " "
        << moved.getCountOfUsedUnits() << std::endl;

    return 0;
}
