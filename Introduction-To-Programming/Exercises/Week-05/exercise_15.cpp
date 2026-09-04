// Дадена е матрица, съдържаща N реда и 3 колони. 
// Да се напише функция, която отпечатва на екрана всички редове, 
// числата от които могат да са страни на триъгълник. Да се използва 
// помощна функция, проверяваща дали три числа са страни на триъгълник.
#include <iostream>

bool can_build_triangle(const int a, const int b, const int c) {
    return (
        (a + b > c) && (a + c > b) && (c + b > a) &&
        (a >= 0) && (b >= 0) && (c >= 0)
    );
}

int main() {
    int N = 0;
    std::cin >> N;
    int current_index = 0;
    int buffer[1024][3];

    for (size_t i = 0; i < N; i++) {
        int a, b, c = 0;
        std::cin >> a >> b >> c;
        if (can_build_triangle(a, b, c)) {
            buffer[current_index][0] = a;
            buffer[current_index][1] = b;
            buffer[current_index][2] = c;
            current_index += 1;
        }
    }

    std::cout << std::endl;
    for (size_t i = 0; i < current_index; i++) {
        std::cout << buffer[i][0] << " " << buffer[i][1] << " " << 
            buffer[i][2] << std::endl;
    }

    return 0;
}