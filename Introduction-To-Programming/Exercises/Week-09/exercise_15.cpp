// Напишете функция, която segfault-ва когато 
// ѝ се подаде числото 5.
#include <iostream>

void segfault_on_five(int number) {
    if (number == 5) {
        int* ptr = nullptr;
        *ptr = 10;
    }
}

int main() {
    segfault_on_five(6);
    segfault_on_five(5);
    return 0;
}