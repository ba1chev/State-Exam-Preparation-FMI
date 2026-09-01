// Да се напише програма, която приема две 
// числа n и m и връща произведението на n * 2m.
#include <iostream>

int main() {
    int n, m = 0;
    std::cin >> n >> m;
    std::cout << n * (1 << m) << std::endl;
    return 0;
}