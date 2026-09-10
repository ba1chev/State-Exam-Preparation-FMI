// Съставете рекурсивна подпрограма, която намира 
// броя на цифрите на дадено цяло положително число.
#include <iostream>

int digits_count(int number) {
    if (!number) {
        return 0;
    }
    return 1 + digits_count(number / 10);
}

int main() {
    std::cout << digits_count(123) << std::endl;
    return 0;
}