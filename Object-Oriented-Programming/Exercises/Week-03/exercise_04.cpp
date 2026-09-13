// Да се напише програма, която чете име на файл filename от стандартния 
// вход и записва съдържанието на filename в същия файл, отрязано наполовина.
#include <iostream>
#include <fstream>

void writeSemiContent(const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    char newLines[100][1024]{};
    size_t currentIndex = 0;
    while (ifs.getline(newLines[currentIndex], sizeof(newLines[currentIndex]))) {
        currentIndex += 1;
    }

    ifs.clear();
    ifs.close();

    std::ofstream ofs(fileName);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    size_t upperBound = currentIndex / 2;
    for (size_t i = 0; i < upperBound; i++) {
        ofs << newLines[i] << std::endl;
    }
    
    ofs.clear();
    ofs.close();
}

int main() {
    writeSemiContent("test.txt");
    return 0;
}