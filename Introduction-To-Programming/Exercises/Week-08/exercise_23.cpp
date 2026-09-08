// Да се напише програма, която създава текстов файл,
// съдържащ информация за студентите от една група. Всяка компонента на
// файла съдържа: име, факултетен номер и среден успех на студент.
// Програмата да извежда името и средния успех на всеки студент.
#include <iostream>
#include <fstream>
#include <cstring>

struct Student {
public:
    char name[100]{};
    int faculty_number = 0;
    float avarage_grade = 0.0f;
};

void write_student(std::ofstream& ofs, const Student& student) {
    if (!ofs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    ofs << student.name << " ";
    ofs << student.faculty_number << " ";
    ofs << student.avarage_grade << std::endl;
}

Student read_student(std::ifstream& ifs) {
    Student student;
    ifs >> student.name;
    ifs >> student.faculty_number;
    ifs >> student.avarage_grade;

    return student;
}

int get_students_count(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return -1;
    }

    char current_char = 'a';
    int result = 0;
    while (ifs.read((char*)&current_char, sizeof(char))) {
        if (current_char == '\n') {
            result += 1;
        }
    }

    return result;
}

void print_names_and_grades(const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    int students_count = get_students_count(ifs);
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    for (size_t i = 0; i < students_count; i++) {
        Student current_student = read_student(ifs);
        std::cout << current_student.name << " " << current_student.avarage_grade << std::endl;
    }

    ifs.close();
}

int main() {
    Student s1;
    strncpy(s1.name, "Yoan", strlen("Yoan"));
    s1.faculty_number = 47;
    s1.avarage_grade = 5.51f;

    Student s2;
    strncpy(s2.name, "Ilian", strlen("Ilian"));
    s2.faculty_number = 31;
    s2.avarage_grade = 4.44f;

    std::ofstream ofs("file.txt");
    write_student(ofs, s1);
    write_student(ofs, s2);
    ofs.close();

    print_names_and_grades("file.txt");

    return 0;
}
