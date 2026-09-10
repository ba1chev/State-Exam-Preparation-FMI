// Да се напише рекурсивна програма, която намира 
// най-големия общ делител на две естествени числа.
#include <iostream>

int nod(int left, int right, int current_candidate) {
    if (current_candidate == 1) {
        return 1;
    }
    if (!(left % current_candidate) && !(right % current_candidate)) {
        return current_candidate;
    } else {
        return nod(left, right, current_candidate - 1);
    }
}

int main() {
    std::cout << nod(21, 28, std::min(21, 28)) << std::endl;
    std::cout << nod(7, 13, std::min(7, 13)) << std::endl;
    return 0;
}