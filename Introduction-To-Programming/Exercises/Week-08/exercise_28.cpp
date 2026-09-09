// В текстов файл е записана редица от числа, разделени с 
// интервали, табулации или преминаване на нов ред. Да се 
// намери средно-аритметичното на числата.
#include <iostream>
#include <fstream>

void read_and_calc_avarage(const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "Cannot open the file" << std::endl;
        return;
    }

    float current_number = 0;
    float number_sum = 0;
    int number_count = 0;
    while (ifs >> current_number) {
        number_sum += current_number;
        number_count += 1;
    }

    ifs.close();
    std::cout << (number_sum / (number_count + 0.0f)) << std::endl;
}

int main() {
    read_and_calc_avarage("file.txt");
    return 0;
}