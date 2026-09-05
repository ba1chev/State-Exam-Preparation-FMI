// Дадени са N на брой цели положителни числа разположени в кръг 
// (т.е последното и първото са съседи) и число K, такова че N и K 
// са взаимно прости (т.е нямат общи делители, освен единицата). 
// Започвайки от нулевия елемент, да се изведат всички числа от кръга, 
// придвижвайки се с K позиции на всяка итерация.
// Ограничения: 2 <= N <= 1024
#include <iostream>

int NOD(int number_1, int number_2) {
    int result = 1;
    int min_number = (number_1 + number_2 - std::abs(number_1 - number_2)) / 2;
    for (size_t i = 1; i <= min_number; i++) {
        if ((number_1 % i == 0) && (number_2 % i == 0)) {
            result = i;
        }
    }

    return result;
}

int main() {
    int N, K = 0;
    std::cin >> N >> K;
    if (N < 2 || N > 1024 || NOD(N, K) != 1) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int array[1024] {};
    for (size_t i = 0; i < N; i++) {
        std::cin >> array[i];
    }
    
    int counter = 0;
    bool seen[1024] {false};
    for (size_t i = 0; i < 1024; i++) {
        seen[i] = false;
    }
    int current_index = 0;
    while (true) {
        if (counter == N) {
            break;
        }
        if (!seen[current_index]) {
            counter += 1;
        }
        std::cout << array[current_index] << " ";
        seen[current_index] = true;
        current_index = (current_index + K) % N;
    }
    
    std::cout << std::endl;
    return 0;
}