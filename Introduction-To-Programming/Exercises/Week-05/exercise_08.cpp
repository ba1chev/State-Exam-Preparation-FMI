// Напишете функция calculate(const int a, const int b, char action),
// където action може да бъде [+-*//%]. Програмата да връща като
// резултат съответното действие, а ако не се укаже символ да върне
// сбора на числата
#include <iostream>

int calculate(const int a, const int b, char action) {
    switch (action) {
        case '+': {
            return a + b;
        }
        case '-': {
            return a - b;
        }
        case '*': {
            return a * b;
        }
        case '/': {
            return a / b;
        }
        case '%': {
            return a % b;
        }
        default: {
            return a + b;
        }
    }
}

int main() {
    std::cout << calculate(10, 13, '+') << " " <<
        calculate(10, 13, '-') << " " << calculate(10, 13, '*') << " " <<
        calculate(10, 13, '/') << " " << calculate(10, 13, '%') << " " <<
        calculate(10, 13, 'D') << std::endl;
    return 0;
}