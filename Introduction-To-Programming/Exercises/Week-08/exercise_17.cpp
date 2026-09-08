// Да се състави програма, която:
// създава файл, съдържащ всички прости числа не надминаващи дадено естествено число n;
// извежда съдържанието на файла на екрана.
#include <iostream>
#include <fstream>

bool is_prime(const int number) {
    for (size_t i = 2; i < number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void write_random_numbers(std::ofstream& ofs, int bound) {
    if (!ofs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return; 
    }

    for (size_t i = 1; i <= bound; i++) {
        if (is_prime(i)) {
            ofs << i << " ";
        }
    }
}

void read_random_numbers(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    int current_number = 0;
    while (ifs >> current_number) {
        std::cout << current_number << " ";
    }
}

int main() {
    int number = 10;
    std::ofstream ofs("file.txt");
    write_random_numbers(ofs, number);
    ofs.close();

    std::ifstream ifs("file.txt");
    read_random_numbers(ifs);
    ifs.close();

    return 0;
}