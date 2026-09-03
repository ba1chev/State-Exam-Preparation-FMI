// Дадени са естествените числа n и m. 
// Да се състави програма, която намира и 
//извежда стойността на произведението: n(n+1)(n+2)…m
#include <iostream>

int main() {
    int n, m = 0;
    std::cin >> n >> m;
    if (n > m) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int result = 1;
    for (size_t i = n; i <= m; i++) {
        result *= i;
    }
    
    std::cout << result << std::endl;
    return 0;
}