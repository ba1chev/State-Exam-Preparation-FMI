// Едно ябълково дърво дава 115 ябълки. В една кошница се побират 80 ябълки. 
// Да се състави програма, която по даден брой дървета извежда 
// колко кошници са необходими, за да се поберат всички ябълки.
#include <iostream>

int main() {
    int count_of_trees = 0;
    std::cin >> count_of_trees;
    if (count_of_trees < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int count_of_apples = 115 * count_of_trees;
    float count_of_baskets = count_of_apples / 80.0f;
    if (count_of_baskets == (int)count_of_baskets) {
        std::cout << count_of_baskets << std::endl;
    } else {
        std::cout << (int)count_of_baskets + 1 << std::endl;
    }

    return 0;
}