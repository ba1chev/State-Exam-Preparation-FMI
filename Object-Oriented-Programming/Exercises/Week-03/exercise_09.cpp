// Да се направи функция, която "разшифрова" скрито съобщение. 
// Съобщението представлява двоичен файл с неизвестна дължина. 
// Това, което съхранява е поредица от цели неотрицателни числа.

// "Ключът" за съобщението се съхранява в друг двоичен файл и представлява 
// число в интервала [0, 255]. Преценете как е най-подходящо да прочетете и 
// съхраните ключа. Шифърът за получаване на правилното съобщение е към всяко 
// число от прочетения файл, съдържащ съобщението да се добави стойността на 
// прочетения ключ

// Пояснение: Aко файлът със скритото съобщение след прочитане изглежда така: 
// 23 48 3 12 4006, файлът, съдържащ ключа има стойност 2, то разшифрованото 
// съобщение трябва да е: 25 50 5 14 4008. Изведете разшифрованото съобщение 
// на конзолата.
#include <iostream>
#include <fstream>

void decipher(const char* fileName, const char* keyFileName) {
    if (!fileName || !keyFileName) {
        throw std::runtime_error("Nullptr detected");
    }

    uint8_t key = 0;
    std::ifstream ifs1(keyFileName, std::ios::binary);
    if (!ifs1.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }
    ifs1.read((char*)&key, sizeof(uint8_t));
    ifs1.clear();
    ifs1.close();

    std::ifstream ifs2(fileName, std::ios::binary);
    if (!ifs2.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    unsigned int currentNumber = 0;
    while (ifs2.read((char*)&currentNumber, sizeof(unsigned int))) {
        std::cout << currentNumber + key << " ";
    }

    ifs2.clear();
    ifs2.close();
}

int main() {
    decipher("data.bin", "key.bin");
    return 0;
}