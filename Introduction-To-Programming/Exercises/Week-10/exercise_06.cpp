// Дадени са N на брой цели положителни числа разположени в кръг 
// (т.е последното и първото са съседи) и число K, такова че N и K са 
// взаимно прости (т.е нямат общи делители, освен единицата). 
// Започвайки от нулевия елемент, да се изведат всички числа от кръга, 
// придвижвайки се с K позиции на всяка итерация.
#include <iostream>

int get_nod(int left, int right) {
    int max_number = left;
    max_number = (max_number + right + std::abs(max_number - right)) / 2;
    int divider = 1;

    for (size_t i = 2; i <= max_number; i++) {
        if (!(left % i) && !(right % i)) {
            divider = i;
        }
    }
    
    return divider;
}

int main() {
    int N, K = 0;
    std::cin >> N >> K;
    if (N < 0 || K < 0 || get_nod(N, K) != 1) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int* array = new int[N]{};
    bool* seen = new bool[N]{};
    int seen_counter = 0;
    for (size_t i = 0; i < N; i++) {
        std::cin >> array[i];
        seen[i] = false;
    }
    
    int current_index = 0;
    while (true) {
        if (seen_counter == N) {
            break;
        }
        if (!seen[current_index]) {
            seen_counter += 1;
            seen[current_index] = true;
        }
        
        std::cout << array[current_index] << " ";
        current_index = (current_index + K) % N;
    }
    std::cout << std::endl;
    
    delete[] array;
    delete[] seen;
    array = nullptr;
    seen = nullptr;
    return 0;
}