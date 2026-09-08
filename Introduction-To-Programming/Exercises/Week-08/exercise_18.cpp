// Да се състави програма, която:
// създава файл съдържащ цели числа;
// добавя елемент в края на създаденият файл;
// извежда съдържанието на файла на екрана.
#include <iostream>
#include <fstream>

void write_numbers(std::ofstream& ofs, const int* array, int size) {
    if (!ofs.is_open() || !array || size < 0) {
        std::cout << "File cannot open or invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < size; i++) {
        ofs << array[i] << " ";
    }
}

void add_element_in_the_end(std::ofstream& ofs, const int number) {
    if (!ofs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    ofs << number;
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

int main() {
    int numbers[3] = {1, 2, 3};
    std::ofstream ofs("file.txt");
    write_numbers(ofs, numbers, 3);
    add_element_in_the_end(ofs, 4);
    ofs.close();

    std::ifstream ifs("file.txt");
    read_numbers(ifs);
    ifs.close();

    return 0;
}