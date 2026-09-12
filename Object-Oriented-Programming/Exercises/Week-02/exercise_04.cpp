// Създайте C++ програма, която чете съобщения от конзолата. Всяко съобщение ще започва с 
// [ERROR] или [INFO], последвано от текст на съобщението с произволна дължина. Програмата трябва 
// да съхранява тези логове в двоичен файл. Освен това, трябва да предоставя начин за показване 
// само на новите съобщения за грешки от последната проверка.
// 1. Четене на вход от конзолата
// Програмата трябва да чете входа непрекъснато.
// Съобщенията трябва да бъдат във формат:
//   [ERROR] текст_на_съобщението
//   [INFO] текст_на_съобщението
// 2. Съхраняване на логовете
// Логовете трябва да се записват в двоичен файл (logs.bin).
// Всеки запис трябва да съдържа типа (ERROR или INFO) и текста на съобщението.
// 3. Проследяване на последната прочетена позиция
// Поддържайте втори файл (last_read_position.bin), който съдържа:
// Името на лог файла.
// Последната прочетена позиция.
#include <iostream>
#include <fstream>
#include <cstring>

namespace UTILS {
    bool isPrefix(const char* left, const char* right) {
        if (!left || !right) {
            throw std::runtime_error("Nullptr detected");
        }

        while (*right != '\0' && *left == *right) {
            left += 1;
            right += 1;
        }

        return *right == '\0';
    }
}

enum class LogType {
    Error, Info
};

struct Log {
public:
    char message[100] = "";
    LogType type = LogType::Info;
};

Log parseLog(const char* buffer) {
    if (!buffer) {
        throw std::runtime_error("Nullptr detected");
    }

    Log result;
    if (UTILS::isPrefix(buffer, "[ERROR]")) {
        result.type = LogType::Error;
        if (strlen(buffer) <= strlen("[ERROR]")) {
            throw std::runtime_error("Invalid input");
        }
        buffer += strlen("[ERROR]");

        while (*buffer != '\0' && *buffer == ' ') {
            buffer += 1;
        }
        size_t currentIndex = 0;
        while (*buffer != '\0') {
            result.message[currentIndex] = *buffer;
            currentIndex += 1;
            buffer += 1;
        }
    } else if (UTILS::isPrefix(buffer, "[INFO]")) {
        result.type = LogType::Info;
        if (strlen(buffer) <= strlen("[INFO]")) {
            throw std::runtime_error("Invalid input");
        }
        buffer += strlen("[INFO]");

        while (*buffer != '\0' && *buffer == ' ') {
            buffer += 1;
        }
        size_t currentIndex = 0;
        while (*buffer != '\0') {
            result.message[currentIndex] = *buffer;
            currentIndex += 1;
            buffer += 1;
        }
    } else {
        throw std::runtime_error("Invalid input");
    }

    return result;
}

void writeLog(const Log& log, std::ofstream& ofs) {
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    size_t logMessageSize = strlen(log.message);
    ofs.write((const char*)& logMessageSize, sizeof(size_t));
    ofs.write((const char*)log.message, strlen(log.message));
    ofs.write((const char*)&log.type, sizeof(LogType));
}

void run(const char* fileName1, const char* fileName2) {
    if (!fileName1 || !fileName2) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ofstream ofs(fileName1, std::ios::binary);
    std::ofstream ofsLast(fileName2, std::ios::binary | std::ios::trunc);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    char currentLine[1024]{};
    while (std::cin.getline(currentLine, sizeof(currentLine))) {
        Log currentLog = parseLog(currentLine);
        writeLog(currentLog, ofsLast);
        writeLog(currentLog, ofs);
    }

    ofs.clear();
    ofsLast.clear();
    ofs.close();
    ofsLast.close();
}

int main() {
    run("logs.bin", "last_read_position.bin");
    return 0;
}