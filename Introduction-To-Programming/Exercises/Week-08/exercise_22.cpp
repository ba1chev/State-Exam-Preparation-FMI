// Да се състави програма, която:
// създава файл елементите на който са структури, съдържащи информация за 
// учениците от една група (име, номер, среден успех, отсъствия);
// програмата да изведе данните за учениците с отличен успех, а след 
// това за тези със слаб успех;
// извежда всички ученици с повече от 14 отсъствия.
#include <iostream>
#include <fstream>
#include <cstring>

struct Student{
public:
    char name[100]{};
    int student_id = 0;
    float avarage_grade = 0.0f;
    int count_of_absences = 0;

    Student() = default;
    Student(const char* name, int student_id, float avarage_grade, int count_of_absences) {
        strncpy(this->name, name, strlen(name));
        this->name[strlen(name)] = '\0';
        this->student_id = student_id;
        this->avarage_grade = avarage_grade;
        this->count_of_absences = count_of_absences;
    }
};

void write_student(std::ofstream& ofs, const Student& student) {
    if (!ofs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    ofs << student.name << " ";
    ofs << student.student_id << " ";
    ofs << student.avarage_grade << " ";
    ofs << student.count_of_absences << std::endl;
}

Student read_student(std::ifstream& ifs) {
    Student student;
    ifs >> student.name;
    ifs >> student.student_id;
    ifs >> student.avarage_grade;
    ifs >> student.count_of_absences;

    return student;
}

int get_students_count(std::ifstream& ifs) {
    int current_position = ifs.tellg();
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    int result = 0;

    char current_char = 'a';
    while (ifs.read((char*)&current_char, sizeof(char))) {
        if (current_char == '\n') {
            result += 1;
        }
    }

    ifs.clear();
    ifs.seekg(current_position, std::ios::beg);
    return result;
}

void print_students(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        std::cout << "Cannot open file" << std::endl;
        return;
    }

    Student students[1024]{};
    int count_of_students = get_students_count(ifs);
    for (size_t i = 0; i < count_of_students; i++) {
        students[i] = read_student(ifs);
    }

    std::cout << "Students with >= 5.50 avarage grade: " << std::endl;
    for (size_t i = 0; i < count_of_students; i++) {
        if (students[i].avarage_grade >= 5.50f) {
            std::cout << students[i].name << " ";
            std::cout << students[i].student_id << " ";
            std::cout << students[i].avarage_grade << " ";
            std::cout << students[i].count_of_absences << std::endl;
        }
    }

    std::cout << std::endl << "Students with < 3.00 avarage grade: " << std::endl;
    for (size_t i = 0; i < count_of_students; i++) {
        if (students[i].avarage_grade < 3.00f) {
            std::cout << students[i].name << " ";
            std::cout << students[i].student_id << " ";
            std::cout << students[i].avarage_grade << " ";
            std::cout << students[i].count_of_absences << std::endl;
        }
    }

    std::cout << std::endl << "Students with >= 14 absences: " << std::endl;
    for (size_t i = 0; i < count_of_students; i++) {
        if (students[i].count_of_absences >= 14) {
            std::cout << students[i].name << " ";
            std::cout << students[i].student_id << " ";
            std::cout << students[i].avarage_grade << " ";
            std::cout << students[i].count_of_absences << std::endl;
        }
    }
}

int main() {
    const char* file_name = "file.txt";
    std::ofstream ofs(file_name);
    Student student1{"Ivan", 101, 5.75f, 3};
    Student student2{"Maria", 102, 6.00f, 5};
    Student student3{"Georgi", 103, 2.50f, 16};
    Student student4{"Elena", 104, 3.25f, 8};
    Student student5{"Nikolay", 105, 5.50f, 18};
    write_student(ofs, student1);
    write_student(ofs, student2);
    write_student(ofs, student3);
    write_student(ofs, student4);
    write_student(ofs, student5);
    
    std::ifstream ifs(file_name);
    print_students(ifs);
    ifs.seekg(0, std::ios::beg);

    ifs.close();
    ofs.close();
    return 0;
}