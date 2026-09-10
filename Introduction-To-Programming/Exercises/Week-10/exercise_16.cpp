// Дадена е квадратна матрица A с размери nxn. 
// Изведете елементите й спираловидно, започвайки от горния ляв ъгъл.
#include <iostream>
#include <climits>

void print_spiral_matrix(int** array, int N) {
    if (!array || N < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int counter = 0;
    int targeted_blocks = N * N;

    int i = 0;
    int j = 0;
    while (true) {
        if (counter == targeted_blocks) {
            break;
        }

        while (j < N) {
            if (array[i][j] != INT_MAX) {
                std::cout << array[i][j] << " ";
                array[i][j] = INT_MAX;
                counter += 1;
                j += 1;
            } else {
                break;
            }
        }
        j -= 1;
        i += 1;

        while (i < N) {
            if (array[i][j] != INT_MAX) {
                std::cout << array[i][j] << " ";
                array[i][j] = INT_MAX;
                counter += 1;
                i += 1;
            } else {
                break;
            }
        }
        i -= 1;
        j -= 1;

        while (j >= 0) {
            if (array[i][j] != INT_MAX) {
                std::cout << array[i][j] << " ";
                array[i][j] = INT_MAX;
                counter += 1;
                j -= 1;
            } else {
                break;
            }
        }
        j += 1;
        i -= 1;

        while (i >= 0) {
            if (array[i][j] != INT_MAX) {
                std::cout << array[i][j] << " ";
                array[i][j] = INT_MAX;
                counter += 1;
                i -= 1;
            } else {
                break;
            }
        }
        i += 1;
        j += 1;
    }
    std::cout << std::endl;
}

int main() {
    int N = 0;
    std::cin >> N;
    if (N < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    int** array = new int*[N]{nullptr};
    for (size_t i = 0; i < N; i++) {
        array[i] = new int[N]{};
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            std::cin >> array[i][j];
        }
    }
    print_spiral_matrix(array, N);

    for (size_t i = 0; i < N; i++) {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    return 0;
}