// Напишете функция pow(const int num, const unsigned N), 
// която връща като резултат числото num повдигнато на степен N, 
// където N е строго положително
#include <iostream>

int pow(const int num, const unsigned N) {
    int result = 1;
    for (size_t i = 0; i <  N; i++) {
        result *= num;
    }
    
    return result;
}

int main() {
    std::cout << pow(2, 4) << " " << pow(5, 2) << std::endl;
    return 0;
}