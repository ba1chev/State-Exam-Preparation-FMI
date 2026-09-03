// Да се състави програма, която по въведено 
// естествено число n да изведе всички естествени 
// решения на уравнението x+y=n.
#include <iostream>

int main() {
    int n = 0;
    std::cin >> n;

    for (size_t i = 1; i < n; i++) {
        for (size_t j = 1; j < n; j++) {
            if (i + j == n) {
                std::cout << "x = " << i <<
                    ", y = " << j << std::endl;
            }
        }
    }
    
    return 0;
}