// Да се напише програма, 
// която приема число n и установява дали m-тия бит е 1.
#include <iostream>

int main() {
    int n, m = 0;
    std::cin >> n >> m;
    if (m < 0 || m > 31) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    bool is_up = (n & (1 << m));
    std::cout << is_up << std::endl;
    return 0;
}