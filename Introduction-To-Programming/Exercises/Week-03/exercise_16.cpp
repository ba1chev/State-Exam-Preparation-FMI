// Напишете програма, която получава две числа от 
// конзолата и връща най-голямата възможна стойност от 
// следните математически операции с тях:
//  събиране, изваждане, умножение или деление.
#include <iostream>

const int get_min_element(const int a, const int b) {
    if (a <= b) {
        return a;
    }
    return b;
}

int main() {
    int a, b, c= 0;
    std::cin >> a >> b >> c;
    int first = get_min_element(
        get_min_element(a, b), c
    );
    
    std::cout << first << " ";
    if (first == a) {
        int second = get_min_element(b, c);
        if (second == b) {
            std::cout << b << " " << c << std::endl;
        } else {
            std::cout << c << " " << b << std::endl;
        }

    } else if (first == b) {
        int second = get_min_element(a, c);
        if (second == a) {
            std::cout << a << " " << c << std::endl;            
        } else {
            std::cout << c << " " << a << std::endl;
        }
    } else if (first == c) {
        int second = get_min_element(a, b);
        if (second == a) {
            std::cout << a << " " << b << std::endl;
        } else {
            std::cout << b << " " << a << std::endl;
        }
    }

    return 0;
}