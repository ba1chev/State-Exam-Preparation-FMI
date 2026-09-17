// Да се реализира клас KBaseNumber, който да служи за работа с числа в 
// k-ична бройна система. Всяко число се представя като символен низ с 
// максимална дължина 64. Класът да поддържа следните функционалности:

// Конвертиране на числото в друга бройна система
// Сравняване с друго число
// Промяна на числото и основата на бройната система
// Принтиране на числото по подходящ начин
// Четене и записване в двоичен файл
#include <iostream>
#include <fstream>
#include <cstring>

namespace UTILS {
    bool isDigit(const char ch) {
        return (ch >= '0') && (ch <= '9');
    }

    int digitValue(const char ch) {
        if (UTILS::isDigit(ch)) {
            return (int)ch - (int)'0';
        }
        if (ch >= 'A' && ch <= 'F') {
            return 10 + ((int)ch - (int)'A');
        }
        throw std::runtime_error("Invalid input");
    }

    long long tenBasedNumber(const char* string, const size_t kBase) {
        if (!string) {
            throw std::runtime_error("Nullptr detected");
        }

        long long iter = 1;
        long long result = 0;
        size_t stringSize = strlen(string);
        for (int i = stringSize - 1; i >= 0; i--) {
            result += UTILS::digitValue(string[i]) * iter;
            iter *= kBase;
        }

        return result;
    }

    char toChar(int digit) {
        if (digit > 9 || digit < 0) {
            throw std::runtime_error("Invalid input");
        }
        return (char)((int)digit + (int)'0');
    }
}

class KBaseNumber {
private:
    char number[64 + 1] = "0";
    size_t kBase = 10;

public:
    KBaseNumber() = default;

    KBaseNumber(const char* number, const size_t kBase) {
        if (!number || kBase > 16) {
            throw std::runtime_error("Invalid constructor input");
        }
        this->kBase = kBase;
        strncpy(this->number, number, strlen(number));
    }

    void print() const {
        std::cout << this->number;
        std::cout << "(" << this->kBase << ")" << std::endl;
    }

    void printConvertedTo(const int kBase) {
        if (kBase > 16 || kBase < 0) {
            throw std::runtime_error("Invalid input");
        }

        long long tenBasedNumber = UTILS::tenBasedNumber(this->number, this->kBase);
        long long copyOfTenBasedNumber = tenBasedNumber;
        size_t neededCapacity = 0;

        while (copyOfTenBasedNumber != 0) {
            neededCapacity += 1;
            copyOfTenBasedNumber /= kBase;
        }
        
        char* transformedNumber = new char[neededCapacity + 1]{};
        size_t currentIndex = 0;
        while (tenBasedNumber != 0) {
            int currentRemainder = tenBasedNumber % kBase;
            if (currentRemainder > 9) {
                transformedNumber[currentIndex] = (char)((int)currentRemainder - 10 + (int)'A');
            } else {
                transformedNumber[currentIndex] = UTILS::toChar(currentRemainder);
            }
            currentIndex += 1;
            tenBasedNumber /= kBase;
        }

        transformedNumber[neededCapacity] = '\0';
        for (size_t i = 0; i < neededCapacity / 2; i++) {
            std::swap(transformedNumber[i], transformedNumber[neededCapacity - i - 1]);
        }
        strncpy(this->number, transformedNumber, strlen(transformedNumber));
        this->kBase = kBase;

        std::cout << transformedNumber << std::endl;
        delete[] transformedNumber;
        transformedNumber = nullptr;
    }

    int compareWith(const KBaseNumber& other) const {
        long long first = UTILS::tenBasedNumber(this->number, this->kBase);
        long long second = UTILS::tenBasedNumber(other.number, other.kBase);

        if (first > second) {
            return 1;
        } else if (first < second) {
            return -1;
        } else {
            return 0;
        }
    }

    void saveToFile(const char* fileName) const {
        if (!fileName) {
            throw std::runtime_error("Nullptr detected");
        }

        std::ofstream ofs(fileName, std::ios::binary);
        if (!ofs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        size_t numberSize = strlen(this->number);
        ofs.write((const char*)&this->kBase, sizeof(size_t));
        ofs.write((const char*)&numberSize, sizeof(size_t));
        ofs.write((const char*)this->number, strlen(this->number) * sizeof(char));

        ofs.clear();
        ofs.close();
    }

    void readFromFile(const char* fileName) {
        if (!fileName) {
            throw std::runtime_error("Nullptr detected");
        }
        
        std::ifstream ifs(fileName, std::ios::binary);
        if (!ifs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        size_t numberSize = 0;
        ifs.read((char*)&this->kBase, sizeof(size_t));
        ifs.read((char*)&numberSize, sizeof(size_t));
        if (numberSize > 64) {
            throw std::runtime_error("Invalid input");
        }
        ifs.read((char*)this->number, numberSize * sizeof(char));
        this->number[numberSize] = '\0';

        ifs.clear();
        ifs.close();
    }

    void update(const char* number, const int kBase) {
        if (!number || kBase < 0 || kBase > 16) {
            throw std::runtime_error("Invalid input");
        }

        strncpy(this->number, number, strlen(number));
        this->kBase = kBase;
    }
};

int main() {
    KBaseNumber number1("CE9A", 16);
    number1.print(); // CE9A(16)
    number1.printConvertedTo(8); // 147232(8)

    KBaseNumber number2("147232", 8);
    std::cout << number1.compareWith(number2) << std::endl; // 0

    number2.update("1312", 4);
    std::cout << number2.compareWith(number1) << std::endl; // -1

    KBaseNumber number3;
    number1.saveToFile("file.bin");
    number3.readFromFile("file.bin");
    number3.print();
    return 0;
}