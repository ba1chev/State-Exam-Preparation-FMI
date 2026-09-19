#include "exercise_04.h"

int main() {
    NumberSeries series(1, [](const int prev){ return prev + 2; });

    std::cout << series.generateIElement(0) << std::endl;
    std::cout << series.generateIElement(4) << std::endl;
    std::cout << series.generateIElement(2) << std::endl;

    std::cout << series.hasElement(7) << std::endl;
    std::cout << series.hasElement(8) << std::endl;

    NumberSeries copy = series;
    std::cout << copy.generateIElement(4) << std::endl;

    series.setSeriesPredicate([](const int prev){ return prev * 2; });
    std::cout << series.generateIElement(4) << std::endl;

    series.setFirstElement(10);
    std::cout << series.generateIElement(3) << std::endl;

    return 0;
}