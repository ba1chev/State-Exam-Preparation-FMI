// Напишете програма, която чете Markdown таблица със студенти със следните 
// полета: Име (до 50 символа), Факултетен номер (точно 10 символа), Средна 
// оценка (реално число). Със стартирането на програмата потребителят трябва 
// да въведе име на файл, който да бъде зареден в паметта. Всяка таблица да 
// може да съдържа инфромация за най-много 50 студенти.
// Напишете функция, която при подаден факултетен номер отпечатва информация 
//за студента. Напишете функция, която по подаден факултетен номер променя 
// оценката на студента. Напишете функция, която записва студентите обратно 
// във формат Markdown таблица, за да може програмата да прочете актуализираните 
// данни при следващо стартиране.
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

struct MDRow {
public:
    char name[50 + 1] = "";
    char fnId[10 + 1] = "";
    float avarageGrade = 2.0f;
};

struct MDTable {
public:
    MDRow rows[50]{};
    size_t countOfRows = 0;
};

size_t getMdRowsCount(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        throw std::runtime_error("Cannot open file");
    }

    size_t currentPosition = ifs.tellg();
    ifs.seekg(0, std::ios::beg);

    size_t counter = 0;
    char buffer[1024]{};
    while (ifs.getline(buffer, sizeof(buffer))) {
        counter += 1;
    }

    ifs.clear();
    ifs.seekg(currentPosition, std::ios::beg);
    return counter - 2;
}

void copyTrimmedField(const char* begin, const char* end, char* dest, size_t destSize) {
    while (begin < end && *begin == ' ') {
        begin += 1;
    }
    while (end > begin && *(end - 1) == ' ') {
        end -= 1;
    }

    size_t index = 0;
    while (begin < end && index + 1 < destSize) {
        dest[index] = *begin;
        index += 1;
        begin += 1;
    }
    dest[index] = '\0';
}

MDRow parseMdRow(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        throw std::runtime_error("Cannot open file");
    }

    MDRow result;
    size_t fieldCounter = 0;

    char line[1024]{};
    ifs.getline(line, sizeof(line));

    const char* fieldBegin = nullptr;
    for (const char* linePtr = line; ; linePtr += 1) {
        if (*linePtr == '|' || *linePtr == '\0') {
            if (fieldBegin != nullptr) {
                switch (fieldCounter) {
                    case 0: {
                        copyTrimmedField(fieldBegin, linePtr, result.name, sizeof(result.name));
                        break;
                    }
                    case 1: {
                        copyTrimmedField(fieldBegin, linePtr, result.fnId, sizeof(result.fnId));
                        break;
                    }
                    case 2: {
                        char gradeBuffer[32]{};
                        copyTrimmedField(fieldBegin, linePtr, gradeBuffer, sizeof(gradeBuffer));
                        result.avarageGrade = atof(gradeBuffer);
                        break;
                    }
                }
                fieldCounter += 1;
            }

            if (*linePtr == '\0') {
                break;
            }
            fieldBegin = linePtr + 1;
        }
    }

    return result;
}

MDTable parseMdTable(const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Invalid input");
    }

    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        throw std::runtime_error("Cannot open file");       
    }

    MDTable result;
    char buffer[1024]{};
    ifs.getline(buffer, sizeof(buffer));
    ifs.getline(buffer, sizeof(buffer));
    result.countOfRows = getMdRowsCount(ifs);
    for (size_t i = 0; i < result.countOfRows; i++) {
        result.rows[i] = parseMdRow(ifs);
    }
    
    ifs.clear();
    ifs.close();
    return result;
}

void printStudentByFnId(const MDTable& table, const char* fnId) {
    if (!fnId) {
        throw std::runtime_error("Invalid function input");
    }

    for (size_t i = 0; i < table.countOfRows; i++) {
        if (!strcmp(table.rows[i].fnId, fnId)) {
            const MDRow& row = table.rows[i];
            std::cout << row.name << " ";
            std::cout << row.fnId << " ";
            std::cout << row.avarageGrade << std::endl;
            return;
        }
    }

    throw std::runtime_error("Not found");
}

void changeStudentGradeByFnId(MDTable& table, const char* fnId, const float newGrade) {
    if (!fnId) {
        throw std::runtime_error("Invalid function input");
    }

    for (size_t i = 0; i < table.countOfRows; i++) {
        if (!strcmp(table.rows[i].fnId, fnId)) {
            MDRow& row = table.rows[i];
            row.avarageGrade = newGrade;
            return;
        }
    }

    throw std::runtime_error("Not found");
}

void deserializeMdRow(const MDRow& row, std::ofstream& ofs) {
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    ofs << "| " << row.name << " | ";
    ofs << row.fnId << " | ";
    ofs << row.avarageGrade << " |" << std::endl;
}

void deserializeMdTable(const MDTable& table, const char* fileName) {
    if (!fileName) {
        throw std::runtime_error("Invalid function input");
    }

    std::ofstream ofs(fileName);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    ofs << "| Name | Faculty Number | Grade |" << std::endl;
    ofs << "|------|----------------|-------|" << std::endl;
    for (size_t i = 0; i < table.countOfRows; i++) {
        deserializeMdRow(table.rows[i], ofs);
    }

    ofs.clear();
    ofs.close();
}

int main() {
    char fileName[256]{};
    std::cout << "Enter file name: ";
    std::cin >> fileName;

    MDTable table = parseMdTable(fileName);
    printStudentByFnId(table, "0MI0600328");
    changeStudentGradeByFnId(table, "0MI0600328", 6.00f);
    printStudentByFnId(table, "0MI0600328");
    deserializeMdTable(table, "result.md");

    return 0;
}