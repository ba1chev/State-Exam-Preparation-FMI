// Напишете програма, която отпечатва собствения си код.
#include <iostream>
#include <fstream>

void printItself(const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Invalid input");
    }

    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot open");
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