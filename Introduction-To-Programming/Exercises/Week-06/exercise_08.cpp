// Дадени са редицата от цели числа а0, а1, а2, …, аn-1 (0< n < 100) и 
// цяло число х. Да се състави прог­рама, която проверява дали х се 
// съдържа в реди­цата а0, а1, а2, …, аn-1 (последователно търсене).
#include <iostream>

int main() {
    int array_1[7] = {1, 55, 120, 120, 450, 888, 9123};
    int k = 7;
    int target = 0;
    std::cin >> target;

    bool found = false;
    for (size_t i = 0; i < k; i++) {
        if (array_1[i] == target) {
            found = true;
            break;
        }
    }

    std::cout << found << std::endl;
    return 0;
}