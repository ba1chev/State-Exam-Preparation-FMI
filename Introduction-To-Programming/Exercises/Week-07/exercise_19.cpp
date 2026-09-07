// Дадена е квадратна матрица A с размери nxn. 
// Изведете елементите й спираловидно, започвайки от горния ляв ъгъл.
#include <iostream>

void spiral_matrix(int** matrix, int N, int M) {
    int target_visited = N * M;
    int counter = 0;

    int i = 0;
    int j = 0;
    while (true) {
        if (counter == target_visited) {
            break;
        }

        while (j < M && matrix[i][j] != INT_MAX) {
            std::cout << matrix[i][j] << " ";
            matrix[i][j] = INT_MAX;
            counter += 1;
            j += 1;
        }
        i += 1;
        j -= 1;

        while (i < N && matrix[i][j] != INT_MAX) {
            std::cout << matrix[i][j] << " ";
            matrix[i][j] = INT_MAX;
            counter += 1;
            i += 1;
        }
        i -= 1;
        j -= 1;

        while (j >= 0 && matrix[i][j] != INT_MAX) {
            std::cout << matrix[i][j] << " ";
            matrix[i][j] = INT_MAX;
            counter += 1;
            j -= 1;
        }
        i -= 1;
        j += 1;

        while (i >= 0 && matrix[i][j] != INT_MAX) {
            std::cout << matrix[i][j] << " ";
            matrix[i][j] = INT_MAX;
            counter += 1;
            i -= 1;
        }
        i += 1;
        j += 1;
    }
    std::cout << std::endl;
}

int main() {
    int N = 0;
    int M = 0;
    std::cin >> N >> M;
    if (N < 0 || M < 0 || N > 10 || M > 10) {
        std::cout << "Invaid input" << std::endl;
        return 1;
    }

    int** matrix = new int*[N]{nullptr};
    for (size_t i = 0; i < N; i++) {
        matrix[i] = new int[M]{};
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            std::cin >> matrix[i][j];
        }
    }
    spiral_matrix(matrix, N, M);

    for (size_t i = 0; i < N; i++) {
        delete[] matrix[i];
        matrix[i] = nullptr;
    }
    delete[] matrix;
    matrix = nullptr;
    return 0;
}