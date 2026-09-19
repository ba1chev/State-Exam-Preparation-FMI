#include "exercise_04.h"

int main() {
    NumberSeries series(1, [](const int prev){ return prev + 2; });

    std::cout << series.generateIElement(0) << std::endl; // 1
    std::cout << series.generateIElement(4) << std::endl; // 9
    std::cout << series.generateIElement(2) << std::endl; // 5 (cached)

    std::cout << series.hasElement(7) << std::endl; // 1
    std::cout << series.hasElement(8) << std::endl; // 0

    NumberSeries copy = series;
    std::cout << copy.generateIElement(4) << std::endl; // 9 (independent copy)

    series.setSeriesPredicate([](const int prev){ return prev * 2; });
    std::cout << series.generateIElement(4) << std::endl; // 16 (1,2,4,8,16)

    series.setFirstElement(10);
    std::cout << series.generateIElement(3) << std::endl; // 80 (10,20,40,80)

    return 0;
}