// Дадени са редицата от цели числа а0, а1, …, аn-1 (0 < n < 50) 
// и цяло число х. Да се състави прог­рама, която намира колко пъти х 
// се съдържа в ре­дицата.
#include <iostream>

int main() {
    int array_1[7] = {1, 55, 120, 120, 450, 888, 9123};
    int k = 7;
    int target = 0;
    std::cin >> target;

    int counter = 0;
    for (size_t i = 0; i < k; i++) {
        if (array_1[i] == target) {
            counter += 1;
        }
    }

    std::cout << counter << std::endl;
    return 0;
}
