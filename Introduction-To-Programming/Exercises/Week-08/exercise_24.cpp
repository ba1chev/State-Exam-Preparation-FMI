// Да се напише програма, която сгъстява текстов файл, като изтрива всички интервали 
// в него.
#include <iostream>
#include <fstream>
#include <cstring>

void trim_intervals(const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }

    char current_byte = 'a';
    char file_content[1024]{};
    int current_index = 0;
    while (ifs.read((char*)&current_byte, sizeof(char))) {
        if (current_byte == ' ' || current_byte == '\t' || current_byte == '\n' ||
            current_byte == '\r' || current_byte == '\v' || current_byte == '\f') {
            continue;
        }
        file_content[current_index] = current_byte;
        current_index += 1;
    }
    ifs.close();
    file_content[current_index] = '\0';
    std::ofstream ofs(file_name);
    if (!ofs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }

    ofs << file_content;
    ofs.close();
}

int main() {
    trim_intervals("file.txt");
    return 0;
}