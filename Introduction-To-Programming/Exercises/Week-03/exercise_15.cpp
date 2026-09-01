// Напишете програма, която получава две числа от 
// конзолата и връща най-голямата възможна стойност от 
// следните математически операции с тях:
//  събиране, изваждане, умножение или деление.
#include <iostream>

const int get_max_element(const int a, const int b) {
    if (a >= b) {
        return a;
    }
    return b;
}

int main() {
    int a, b = 0;
    std::cin >> a >> b;

    int multiplication = a * b;
    int addition = a + b;
    int subtraction = a - b;
    int division = a / b;

    std::cout << get_max_element(get_max_element(
        get_max_element(multiplication, addition), 
        subtraction), division) << std::endl;

    return 0;
}
