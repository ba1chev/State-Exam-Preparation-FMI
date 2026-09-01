// Да се напише програма, 
// която приема число n и връща -n - 1.
#include <iostream>

int main() {
    int number = 0;
    std::cin >> number;
    std::cout << ~number << std::endl;
    return 0;
}