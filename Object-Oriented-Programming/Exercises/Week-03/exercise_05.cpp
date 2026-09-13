// Да се напише програма, която реализира UNIX командата wc. wc е команда, 
// която приема име на файл filename и извежда броя нови редове, думи и байтове 
// във файла с име filename.
#include <iostream>
#include <fstream>

enum class WCFlag {
    L, B, C
};

size_t getCountOfLines(std::ifstream& ifs) {
    size_t currentPosition = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    size_t counter = 0;
    char currentByte = 'a';
    while (ifs.get(currentByte)) {
        if (currentByte == '\n') {
            counter += 1;
        }
    }

    ifs.clear();
    ifs.seekg(currentPosition, std::ios::beg);
    return counter;
}

size_t getCountOfBytes(std::ifstream& ifs) {
    size_t currentPosition = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    size_t counter = 0;
    char currentByte = 'a';
    while (ifs.get(currentByte)) {
        counter += 1;
    }

    ifs.clear();
    ifs.seekg(currentPosition, std::ios::beg);
    return counter;
}

size_t getCountOfWords(std::ifstream& ifs) {
    size_t currentPosition = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    size_t counter = 0;
    bool insideWord = false;
    char currentByte = 'a';
    while (ifs.get(currentByte)) {
        if (currentByte == ' ' || currentByte == '\n' || currentByte == '\t') {
            insideWord = false;
        } else if (!insideWord) {
            insideWord = true;
            counter += 1;
        }
    }

    ifs.clear();
    ifs.seekg(currentPosition, std::ios::beg);
    return counter;
}

void wcImplementation(const char* fileName, WCFlag flag) {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    switch (flag) {
        case WCFlag::L: {
            std::cout << getCountOfLines(ifs) << std::endl;
            break;
        }
        case WCFlag::B: {
            std::cout << getCountOfBytes(ifs) << std::endl;
            break;
        }
        case WCFlag::C: {
            std::cout << getCountOfWords(ifs) << std::endl;
            break;
        }
        default: {
            throw std::runtime_error("Unsupported wc flag");
        }
    }

    ifs.clear();
    ifs.close();
}

int main() {
    wcImplementation("exercise_05.cpp", WCFlag::B);    
    wcImplementation("exercise_05.cpp", WCFlag::L);
    wcImplementation("exercise_05.cpp", WCFlag::C);
    return 0;
}