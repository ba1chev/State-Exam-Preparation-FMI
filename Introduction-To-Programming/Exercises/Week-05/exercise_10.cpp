// Напишете функция, която да получава average(const int N, ...), 
// която получава параметър N, който указва колко числа ще се подадат, 
// а след това връща като средното на числата, които потребителят е подал след N.
#include <iostream>

float average(const int N) {
    float current_number = 0;
    float sum = 0.0f;
    for (size_t i = 0; i < N; i++) {
        std::cin >> current_number;
        sum += current_number;
    }
    
    return sum / N;
}

int main() {
    std::cout << average(5) << std::endl;
    return 0;
}