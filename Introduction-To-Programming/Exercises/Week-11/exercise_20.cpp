// Дадени са n града (n е естествено число, 1 ≤ n ≤ 10) и целочислена матрица Anxn, така че aij 
// е равно на 1, ако има пряк път от град i до град j и е 0 в противен случай (0 ≤ i, j ≤ n-1). 
// Да се напише програма, която установява дали съществува път между два произволно зададени 
// града (Приемаме, че ако от град i до град j има път, то има път и от град j до град i).
#include <iostream>

bool has_path(int** array, int n, int current_city, int target_city, bool* visited) {
    if (current_city == target_city) {
        return true;
    }

    visited[current_city] = true;
    int* current_row = array[current_city];
    for (size_t i = 0; i < n; i++) {
        if (current_row[i] == 1 && !visited[i]) {
            if (has_path(array, n, i, target_city, visited)) {
                return true;
            } 
        }
    }
    
    return false;
}

int main() {
    int n = 0;
    std::cin >> n;
    if (n < 1 || n > 10) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** array = new int*[n]{nullptr};
    for (size_t i = 0; i < n; i++) {
        array[i] = new int[n]{};
    }
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            std::cin >> array[i][j];
        }
    }

    bool* visited = new bool[n + 1]{false};
    for (size_t i = 0; i < n; i++) {
        visited[i] = false;
    }
    std::cout << has_path(array, n, 0, n - 1, visited) << std::endl;

    for (size_t i = 0; i < n; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    delete[] visited;
    array = nullptr;
    visited = nullptr;
    return 0;
}