// Да се напише програма, която чете името на файл от 
// стандартния вход и извежда цялото съдържание на файла на 
// стандартния изход.
#include <iostream>
#include <fstream>

void printItself(const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    char currentLine[1024]{};
    while (ifs.getline(currentLine, sizeof(currentLine))) {
        std::cout << currentLine << std::endl;
    }

    ifs.clear();
    ifs.close();
}

int main() {
    printItself("exercise_02.cpp");
    return 0;
}