// Да се състави програма, която:
// създава файла "chisla.txt", елементите на който са 100 произволни цели 
// числа от интервала [1,500];
// прочита съдържанието на "chisla.txt" и създава два нови файла 
//съдържащи съответно всички прости и всички щастливи числа съдържащи 
// се във файла "chisla.txt".
#include <iostream>
#include <fstream>
#include <time.h>
#include <unistd.h>

bool is_prime(const int number) {
    if (number < 2) {
        return false;
    }
    for (size_t i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

bool is_happy(int number) {
    while (number != 1 && number != 4) {
        int sum_of_squares = 0;
        while (number > 0) {
            int digit = number % 10;
            sum_of_squares += digit * digit;
            number /= 10;
        }
        number = sum_of_squares;
    }
    return number == 1;
}

int main() {
    std::srand(time(nullptr));
    std::ofstream ofs("chisla.txt");
    if (!ofs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return 1;
    }

    int left_bound = 1;
    int right_bound = 500;
    for (size_t i = 0; i < 100; i++) {
        int random_number = std::rand() % 
            (right_bound - left_bound + 1) + left_bound;
        ofs << random_number << " ";
    }
    ofs.close();

    std::ifstream ifs("chisla.txt");
    std::ofstream ofs_1("prosti.txt");
    std::ofstream ofs_2("shtastlivi.txt");
    if (!ifs.is_open() || !ofs_1.is_open() || !ofs_2.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return 1;
    }

    int current_number = 0;
    while (ifs >> current_number) {
        if (is_prime(current_number)) {
            ofs_1 << current_number << " ";
        }
        if (is_happy(current_number)) {
            ofs_2 << current_number << " ";
        }
    }

    ofs_1.close();
    ofs_2.close();
    ifs.close();
    return 0;
}