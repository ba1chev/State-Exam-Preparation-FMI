// Да се напише програма, която приема естествено число n и 
// изписва стълба от 1 до n
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << std::endl;

    for (size_t i = 1; i <= n; i++) {
        for (size_t j = 1; j <= i; j++) {
            std::cout << j;   
        }
        std::cout << std::endl;
    }
    
    return 0;
}