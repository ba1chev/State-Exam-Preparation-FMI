// Напишете функция, която намира големината на файл.
#include <iostream>
#include <fstream>

size_t getFileSize(const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Invalid input");
    }

    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot open");
    }
    ifs.seekg(0, std::ios::end);
    size_t result = ifs.tellg();

    ifs.clear();
    ifs.close();
    return result;
}

int main() {
    std::cout << getFileSize("exercise_01.cpp") << std::endl;
    return 0;
}
