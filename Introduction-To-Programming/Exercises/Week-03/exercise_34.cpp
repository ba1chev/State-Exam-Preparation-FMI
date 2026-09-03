// Да се състави програма, която намира и извежда стойността на n!, 
// където n е положително естествено число.
#include <iostream>

int main() {
    int n = 0;
    int factoriel = 1;
    std::cin >> n;

    for (size_t i = 1; i <= n; i++) {
        factoriel *= i;
    }
    
    std::cout << factoriel << std::endl;
    return 0;
}