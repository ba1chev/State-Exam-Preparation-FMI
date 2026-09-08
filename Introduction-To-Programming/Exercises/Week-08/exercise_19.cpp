// Да се състави програма, която:
//създава файл, съдържащ всички числа на Фибоначи от интервала [1 ; n];
// извежда съдържанието на файла на екрана;
// проверява дали числото k се съдържа във файла
#include <iostream>
#include <fstream>

void write_numbers(std::ofstream& ofs, const int bound) {
    if (!ofs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    int prev_1 = 1;
    int prev_2 = 1;
    ofs << prev_1 << " ";
    while (prev_2 <= bound) {
        ofs << prev_2 << " ";
        int current_number = prev_1 + prev_2;
        prev_1 = prev_2;
        prev_2 = current_number;
    }
}

void read_numbers(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    int current_number = 0;
    while (ifs >> current_number) {
        std::cout << current_number << " ";
    }
}

bool check_k_contains(std::ifstream& ifs, const int k) {
    if (!ifs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return false;
    }

    int current_number = 0;
    while (ifs >> current_number) {
        if (current_number == k) {
            return true;
        }
    }
    
    return false;
}

int main() {
    std::ofstream ofs("file.txt");
    write_numbers(ofs, 20);
    ofs.close();

    std::ifstream ifs("file.txt");
    read_numbers(ifs);
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    std::cout << std::endl;
    std::cout << check_k_contains(ifs, 13) << std::endl;
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    std::cout << check_k_contains(ifs, 12) << std::endl;
    ifs.close();

    return 0;
}