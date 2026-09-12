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

Log readLog(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    Log result;
    size_t logMessageSize = 0;
    ifs.read((char*)&logMessageSize, sizeof(size_t));
    ifs.read((char*)result.message, logMessageSize);
    result.message[logMessageSize] = '\0';
    ifs.read((char*)&result.type, sizeof(LogType));
    return result;
}

void saveLastPosition(const char* logFileName, size_t position, const char* fileName) {
    if (!logFileName || !fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ofstream ofs(fileName, std::ios::binary | std::ios::trunc);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    size_t logFileNameSize = strlen(logFileName);
    ofs.write((const char*)&logFileNameSize, sizeof(size_t));
    ofs.write((const char*)logFileName, logFileNameSize);
    ofs.write((const char*)&position, sizeof(size_t));
    ofs.close();
}

size_t loadLastPosition(const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs.is_open()) {
        return 0;
    }

    char logFileName[256]{};
    size_t logFileNameSize = 0;
    ifs.read((char*)&logFileNameSize, sizeof(size_t));
    ifs.read((char*)logFileName, logFileNameSize);

    size_t position = 0;
    ifs.read((char*)&position, sizeof(size_t));
    ifs.close();
    return position;
}

void run(const char* fileName1, const char* fileName2) {
    if (!fileName1 || !fileName2) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ofstream ofs(fileName1, std::ios::binary | std::ios::app);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    char currentLine[1024]{};
    while (std::cin.getline(currentLine, sizeof(currentLine))) {
        Log currentLog = parseLog(currentLine);
        writeLog(currentLog, ofs);
    }

    ofs.clear();
    ofs.close();
}

void showNewErrors(const char* fileName1, const char* fileName2) {
    if (!fileName1 || !fileName2) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ifstream ifs(fileName1, std::ios::binary);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    size_t lastPosition = loadLastPosition(fileName2);
    ifs.seekg(0, std::ios::end);
    size_t endPosition = ifs.tellg();
    ifs.seekg(lastPosition, std::ios::beg);

    while ((size_t)ifs.tellg() < endPosition) {
        Log currentLog = readLog(ifs);
        if (currentLog.type == LogType::Error) {
            std::cout << currentLog.message << std::endl;
        }
    }

    ifs.close();
    saveLastPosition(fileName1, endPosition, fileName2);
}

int main() {
    run("logs.bin", "last_read_position.bin");
    showNewErrors("logs.bin", "last_read_position.bin");
    return 0;
}