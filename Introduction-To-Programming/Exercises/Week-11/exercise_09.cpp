// Съставете рекурсивна подпрограма, която намира 
// произведението от цифрите на дадено цяло положително число.
#include <iostream>

int sum_of_product_digits(int number) {
    if (!number) {
        return 1;
    }
    return (number % 10) * sum_of_product_digits(number / 10);
}

int main() {
    std::cout << sum_of_product_digits(1234) << std::endl;    
    return 0;
}