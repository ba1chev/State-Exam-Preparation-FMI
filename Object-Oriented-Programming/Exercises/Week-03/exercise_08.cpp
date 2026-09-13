// Нека е дадена структура, представяща студент във ФМИ, като 
// всеки студент се характеризира с факултетен номер, две имена, 
// специалност, курс и група. Нека е даден файл с разширението .csv, 
// представящ база данни от студенти във ФМИ, който съдържа неопределен
// брой редове с информация за студенти, като отделните характеристики на даден 
// студент са разделени със запетаи. Например:

// 9MI0800999,Ime,Familiq,KN,2,1
// Да се реализира програма, която чете име на файл от стандартния вход 
// и позволява да се извършват следните операции над базата данни, 
// съхраняваща се в този файл:

// филтриране на студентите, които са в даден курс;
// промяна групата на студент по даден факултетен номер;
// премахване на студент по даден факултетен номер;
// сортиране на студентите по някакъв ключ.
// След прилагането на поредица от промени по базата данни, 
// информацията за студентите да се запише обратно в същия файл.
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

namespace UTILS {
    size_t getCountOfLines(std::ifstream& ifs) {
        if (!ifs.is_open()) {
            throw std::runtime_error("File cannot be opened");
        }

        size_t currentPosition = ifs.tellg();
        ifs.seekg(0, std::ios::beg);
        size_t counter = 0;
        char dummyBuffer[1024]{};
        while (ifs.getline(dummyBuffer, sizeof(dummyBuffer))) {
            counter += 1;
        }

        ifs.clear();
        ifs.seekg(currentPosition, std::ios::beg);
        return counter;
    }
};

enum class Major {
    SI, KN, AD, IS
};

struct Student {
public:
    char fnId[10 + 1] = "";
    char firstName[20] = "";
    char lastName[20] = "";
    Major major = Major::SI;
    size_t course = 1;
    size_t group = 1;
};

Student parseStudent(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    Student parsedStudent;
    char currentLine[1024]{};
    ifs.getline(currentLine, sizeof(currentLine));
    for (size_t i = 0; i < strlen(currentLine); i++) {
        if (currentLine[i] == ',') {
            currentLine[i] = ' ';
        }
    }
    
    std::stringstream ss(currentLine);
    ss >> parsedStudent.fnId;
    ss >> parsedStudent.firstName;
    ss >> parsedStudent.lastName;
    int studentMajor = 0;
    ss >> studentMajor;
    parsedStudent.major = (Major)studentMajor;
    ss >> parsedStudent.course;
    ss >> parsedStudent.group;

    ss.clear();
    return parsedStudent;
}

void printStudent(const Student& student) {
    std::cout << student.fnId << " ";
    std::cout << student.firstName << " ";
    std::cout << student.lastName << " ";
    std::cout << (int)student.major << " ";
    std::cout << student.course << " ";
    std::cout << student.group << std::endl;
}

Student* parseStudentsFromCSV(const char* fileName, size_t& countOfStudents) {
    if (!fileName) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    countOfStudents = UTILS::getCountOfLines(ifs);
    Student* students = new Student[countOfStudents]{};
    for (size_t i = 0; i < countOfStudents; i++) {
        students[i] = parseStudent(ifs);
    }
    
    ifs.clear();
    ifs.close();
    return students;
}

void writeStudentsToCSV(const char* fileName, const Student* students, size_t countOfStudents) {
    if (!fileName || !students) {
        throw std::runtime_error("Nullptr detected");
    }

    std::ofstream ofs(fileName);
    if (!ofs.is_open()) {
        throw std::runtime_error("File cannot be opened");
    }

    for (size_t i = 0; i < countOfStudents; i++) {
        ofs << students[i].fnId << ",";
        ofs << students[i].firstName << ",";
        ofs << students[i].lastName << ",";
        ofs << (int)students[i].major << ",";
        ofs << students[i].course << ",";
        ofs << students[i].group << std::endl;
    }

    ofs.clear();
    ofs.close();
}

void filterStudentsByCourse(const Student* students, size_t countOfStudents, size_t course) {
    if (!students) {
        throw std::runtime_error("Nullptr detected");
    }

    for (size_t i = 0; i < countOfStudents; i++) {
        if (students[i].course == course) {
            printStudent(students[i]);
        }
    }
}

void changeStudentGroupByFnId(Student* students, size_t countOfStudents, const char* fnId, size_t newGroup) {
    if (!students || !fnId) {
        throw std::runtime_error("Nullptr detected");
    }

    for (size_t i = 0; i < countOfStudents; i++) {
        if (!strcmp(students[i].fnId, fnId)) {
            students[i].group = newGroup;
            break;
        }
    }
}

void removeStudentByFnId(Student* students, size_t& countOfStudents, const char* fnId) {
    if (!students || !fnId) {
        throw std::runtime_error("Nullptr detected");
    }

    size_t targetedIndex = -1;
    for (size_t i = 0; i < countOfStudents; i++) {
        if (!strcmp(students[i].fnId, fnId)) {
            targetedIndex = i;
            break;
        }
    }
    
    if (targetedIndex != -1) {
        for (size_t i = targetedIndex; i < countOfStudents - 1; i++) {
            students[i] = students[i + 1];
        }
        countOfStudents -= 1;
    }
}

typedef bool (*SortingPredicate)(const Student&, const Student&);
void sortStudentsBy(Student* students, size_t countOfStudents, SortingPredicate predicate) {
    if (!students || !predicate) {
        throw std::runtime_error("Nullptr detected");
    }

    for (size_t i = 0; i < countOfStudents - 1; i++) {
        for (size_t j = 0; j < countOfStudents - i - 1; j++) {
            if (predicate(students[j], students[j + 1])) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    size_t countOfStudents = 0;
    Student* students = parseStudentsFromCSV("test.csv", countOfStudents);
    for (size_t i = 0; i < countOfStudents; i++) {
        printStudent(students[i]);
    }
    std::cout << std::endl;

    filterStudentsByCourse(students, countOfStudents, 4);
    std::cout << std::endl;
    removeStudentByFnId(students, countOfStudents, "0MI0600328");
    for (size_t i = 0; i < countOfStudents; i++) {
        printStudent(students[i]);
    }
    std::cout << std::endl;

    auto sortPredicate = [](const Student& left, const Student& right) {
        return left.course < right.course;
    };
    sortStudentsBy(students, countOfStudents, sortPredicate);
    for (size_t i = 0; i < countOfStudents; i++) {
        printStudent(students[i]);
    }
    std::cout << std::endl;

    writeStudentsToCSV("test.csv", students, countOfStudents);

    delete[] students;
    students = nullptr;
    return 0;
}