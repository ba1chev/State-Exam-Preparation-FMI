// Да се състави програма, която:
// създава файл f от реални числа;
// преписва положителните му елементи във файл g;
// извежда съдържанието на двата файла.
#include <fstream>
#include <iostream>

void write_to_file(std::ofstream& ofs, const float* array, int size) {
    if (!ofs.is_open() || !array || size < 0) {
        std::cout << "File cannot open or invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < size; i++) {
        ofs << array[i] << " ";
    }
}

void write_positive_to_file(std::ofstream& ofs, std::ifstream& ifs) {
    if (!ofs.is_open() || !ifs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    float current_number = 0;
    while (ifs >> current_number) {
        if (current_number > 0) {
            ofs << current_number << " ";
        }
    }
}

void read_from_file(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    float current_number = 0;
    while (ifs >> current_number) {
        std::cout << current_number << " ";
    }
    std::cout << std::endl;
}

int main() {
    float array[4] = {3.14f, 10.5f, 101.01f, -1.2f};
    std::ofstream ofs_1("f");
    write_to_file(ofs_1, array, 4);
    ofs_1.close();

    std::ofstream ofs_2("g");
    std::ifstream ifs("f");
    write_positive_to_file(ofs_2, ifs);
    ifs.close();
    ofs_2.close();

    std::ifstream ifs_f("f");
    read_from_file(ifs_f);
    ifs_f.close();

    std::ifstream ifs_g("g");
    read_from_file(ifs_g);
    ifs_g.close();

    return 0;
}