// Да се напише функция, която приема като аргументи имената на два текстови файла. 
// В първия файл са записани две цели числа. 
// Да се запишат сбора и произведението им във втория файл.
#include <iostream>
#include <fstream>

void writeMultAndAdd(const char* fileName1, const char* fileName2) {
    if (!fileName1 || !fileName2) {
        throw std::runtime_error("Nullptr detected");
    } 

    std::ifstream ifs(fileName1);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }
    int leftNumber = 0;
    int rightNumber = 0;
    ifs >> leftNumber >> rightNumber;

    std::ofstream ofs(fileName2);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }
    ofs << (leftNumber + rightNumber) <<  " " << (leftNumber * rightNumber);

    ofs.clear();
    ifs.clear();
    ofs.close();
    ifs.close();
}

int main() {
    writeMultAndAdd("test1.txt", "text2.txt");
    return 0;
}