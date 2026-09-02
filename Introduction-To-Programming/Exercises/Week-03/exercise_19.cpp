// Да се напише програма, която получава 3 числа и 
// да определи дали може да съществува триъгълник с 
// толкова големи страни.
#include <iostream>

int main() {
    int a, b, c = 0;    
    std::cin >> a >> b >> c;
    bool can_build_trianle = (a + b > c) && (a + c > b) && (b + c > a);
    std::cout << can_build_trianle << std::endl;
    return 0;
}