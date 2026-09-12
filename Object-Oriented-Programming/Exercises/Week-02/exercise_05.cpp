// Създайте структура, която представя комплексно число. 
// Реализирайте следните функции:
// Функция, която връща сбора на 2 комплексни числа.
// Функция, която връща произведението на 2 комплексни числа.
// Принтиране на комплексно число.
#include <iostream>

struct ComplexNumber {
public:
    float realPart = 0.0f;
    float imPart = 0.0f;

    ComplexNumber(const float realPart, const float imPart) {
        this->realPart = realPart;
        this->imPart = imPart;
    }
};

ComplexNumber sumOf(const ComplexNumber& left, const ComplexNumber& right) {
    return ComplexNumber(
        left.realPart + right.realPart, 
        left.imPart + right.imPart
    );
}

ComplexNumber productOf(const ComplexNumber& left, const ComplexNumber& right) {
    return ComplexNumber(
        -1 * left.imPart * right.imPart + left.realPart * right.realPart,
        left.realPart * right.imPart + left.imPart * right.realPart
    );
}

void printComplexNumber(const ComplexNumber& number) {
    std::cout << "(" << number.realPart << "," << 
        number.imPart << "i)" << std::endl;
}

int main() {
    ComplexNumber left(1, 1);
    ComplexNumber right(3.14, -25);
    printComplexNumber(sumOf(left, right));
    printComplexNumber(productOf(left, right));
    return 0;
}