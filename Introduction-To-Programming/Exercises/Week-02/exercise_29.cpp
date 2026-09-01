// Да се напише функция, 
// която установява дали едно число е четно или нечетно.
#include <iostream>

bool is_event(int number) {
    return !(number & 1);
}

int main() {
    int number = 0;
    std::cin >> number;
    std::cout << is_event(number) << std::endl;
    return 0;
}