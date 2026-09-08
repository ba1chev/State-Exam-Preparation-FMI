// Да се състави програма, която:
// създава файл елементите на който са записи, съдържащи 
// информация за учениците от една група (име, номер, среден успех);
// програмата да сортира по номера елементите на файла;
// да се изведе съдържанието на файла.
#include <iostream>
#include <fstream>
#include <cstring>

struct Student {
public:
    char name[100]{};
    int student_id = 0;
    float avarage_grade = 0.0f;
};

void write_student_to_file(std::ofstream& ofs, const Student& student) {
    if (!ofs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    ofs << student.name << " ";
    ofs << student.student_id << " ";
    ofs << student.avarage_grade << std::endl;
}

Student read_student_from_file(std::ifstream& ifs) {
    Student student;
    ifs >> student.name;
    ifs >> student.student_id;
    ifs >> student.avarage_grade;

    return student;
}
 
int get_lines_count(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return -1;
    }

    char current_char = 'a';
    int size = 0;
    while (ifs.read((char*)&current_char, sizeof(char))) {
        if (current_char == '\n') {
            size += 1;
        }
    }

    return size;
}

void sort_file_students(const char* file_name) {
    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "Cannot open the file" << std::endl;
        return;
    }
    int students_count = get_lines_count(ifs);
    
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    Student current_student;
    Student* students = new Student[students_count];
    for (size_t i = 0; i < students_count; i++) {
        current_student = read_student_from_file(ifs);
        students[i] = current_student;
        ifs.ignore(1);
    }
    
    for (size_t i = 0; i < students_count - 1; i++) {
        for (size_t j = 0; j < students_count - i - 1; j++) {
            if (students[j].student_id > students[j + 1].student_id) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    
    std::ofstream ofs(file_name);
    if (!ofs.is_open()) {
        std::cout << "Cannot open the file" << std::endl;
        return;
    }
    for (size_t i = 0; i < students_count; i++) {
        write_student_to_file(ofs, students[i]);
    }
    
    delete[] students;
    students = nullptr;
    ofs.close();
    ifs.close();
}

void print_file_students(const char* file_name) {
    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "Cannot open the file" << std::endl;
        return;
    }

    int students_count = get_lines_count(ifs);
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    for (size_t i = 0; i < students_count; i++) {
        Student current_student = read_student_from_file(ifs);
        ifs.ignore(1);
        std::cout << current_student.name << " " << current_student.student_id << " "
            << current_student.avarage_grade << std::endl;
    }

    ifs.close();
}
 
int main() {
    Student s1;
    strncpy(s1.name, "Yoan", strlen("Yoan"));
    s1.student_id = 47;
    s1.avarage_grade = 5.51;

    Student s2;
    strncpy(s2.name, "Ilian", strlen("Ilian"));
    s2.student_id = 31;
    s2.avarage_grade = 4.44;

    std::ofstream ofs("file.txt");
    write_student_to_file(ofs, s1);
    write_student_to_file(ofs, s2);
    ofs.close();

    sort_file_students("file.txt");
    print_file_students("file.txt");

    return 0;
}
