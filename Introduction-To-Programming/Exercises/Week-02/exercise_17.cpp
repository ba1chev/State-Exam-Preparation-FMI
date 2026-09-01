// Напише програма, която въвежда 3
// числа a, b и x и извежда дали x ∈ (a,b)
#include <iostream>

int main() {
    float a, b, x = 0.0;
    std::cin >> a >> b >> x;

    bool is_in = (x > a) && (x < b);
    std::cout << is_in << std::endl;
    return 0;
}