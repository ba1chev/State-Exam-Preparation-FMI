// Да се напише програма, която създава файл, съдържащ информация за 
// студентите от един курс. Всяка компонента на файла съдържа: 
// факултетен номер, име и среден успех на студент. Факултетните 
// номера започват от 42900 и завършват с 43150. Програмата да може 
// да извършва следните действия:
// вмъква компонента за новозаписан студент;
// изтрива компонента за студент;
// променя полето “среден успех” на зададен чрез факултетен номер студент;
// извежда върху екрана компонентите на файла;
// намира студентите с указан успех и ги записва в текстовия файл print.txt.
#include <iostream>
#include <fstream>

struct Student {
public:
    int fn = 0;
    char name[100]{};
    float avarage_grade = 0.0f;
};

Student read_student(std::ifstream& ifs) {
    Student student;
    ifs >> student.fn;
    ifs >> student.name;
    ifs >> student.avarage_grade;

    return student;
}

void remove_i_student(int index, const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }
    int count_of_students = 0;
    char dummy_buffer[1024]{};
    while (ifs.getline(dummy_buffer, sizeof(dummy_buffer))) {
        count_of_students += 1;
    }
    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    if (index < 0 || index >= count_of_students) {
        std::cout << "Invalid function input" << std::endl;
        ifs.close();
        return;
    }
        
    Student* students = new Student[count_of_students]{};
    for (size_t i = 0; i < count_of_students; i++) {
        students[i] = read_student(ifs);
    }
    ifs.close();

    std::ofstream ofs(file_name);
    if (!ofs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }
    for (size_t i = 0; i < count_of_students; i++) {
        if (i == index) {
            continue;
        }
        ofs << students[i].fn << " ";
        ofs << students[i].name << " ";
        ofs << students[i].avarage_grade << std::endl;
    }
    
    ofs.close();
    delete[] students;
    students = nullptr;
}

void append_student(const Student& student, const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    std::ofstream ofs(file_name, std::ios::app);
    if (!ofs.is_open()) {
        std::cout << "Cannot open the file" << std::endl;
        return;
    }

    ofs << student.fn << " ";
    ofs << student.name << " ";
    ofs << student.avarage_grade << std::endl;
    ofs.close();
}

void print_students(const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return; 
    }

    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl; 
        return; 
    }
    int count_of_students = 0;
    char dummy_buffer[1024]{};
    while (ifs.getline(dummy_buffer, sizeof(dummy_buffer))) {
        count_of_students += 1;
    }

    ifs.clear();
    ifs.seekg(0, std::ios::beg);
    Student current_student;
    for (size_t i = 0; i < count_of_students; i++) {
        current_student = read_student(ifs);
        std::cout << current_student.fn << " ";
        std::cout << current_student.name << " ";
        std::cout << current_student.avarage_grade << std::endl;
    }

    ifs.close();
}

void change_grade_by_fn(int fn, float new_grade, const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }
    int count_of_students = 0;
    char dummy_buffer[1024]{};
    while (ifs.getline(dummy_buffer, sizeof(dummy_buffer))) {
        count_of_students += 1;
    }
    ifs.clear();
    ifs.seekg(0, std::ios::beg);

    Student* students = new Student[count_of_students]{};
    for (size_t i = 0; i < count_of_students; i++) {
        students[i] = read_student(ifs);
    }
    ifs.close();

    std::ofstream ofs(file_name);
    if (!ofs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        delete[] students;
        return;
    }
    for (size_t i = 0; i < count_of_students; i++) {
        if (students[i].fn == fn) {
            students[i].avarage_grade = new_grade;
        }
        ofs << students[i].fn << " ";
        ofs << students[i].name << " ";
        ofs << students[i].avarage_grade << std::endl;
    }

    ofs.close();
    delete[] students;
    students = nullptr;
}

void print_students_by_grade(float grade, const char* file_name) {
    if (!file_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    std::ifstream ifs(file_name);
    if (!ifs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        return;
    }
    int count_of_students = 0;
    char dummy_buffer[1024]{};
    while (ifs.getline(dummy_buffer, sizeof(dummy_buffer))) {
        count_of_students += 1;
    }
    ifs.clear();
    ifs.seekg(0, std::ios::beg);

    std::ofstream ofs("print.txt");
    if (!ofs.is_open()) {
        std::cout << "File cannot be opened" << std::endl;
        ifs.close();
        return;
    }
    Student current_student;
    for (size_t i = 0; i < count_of_students; i++) {
        current_student = read_student(ifs);
        if (current_student.avarage_grade == grade) {
            ofs << current_student.fn << " ";
            ofs << current_student.name << " ";
            ofs << current_student.avarage_grade << std::endl;
        }
    }

    ifs.close();
    ofs.close();
}

int main() {
    Student s1 = {42900, "Yoan", 5.51f};
    Student s2 = {42901, "Koki", 4.74f};

    append_student(s1, "file.txt");
    append_student(s2, "file.txt");
    append_student(s1, "file.txt");
    print_students("file.txt");

    remove_i_student(1, "file.txt");
    print_students("file.txt");

    change_grade_by_fn(42900, 6.00f, "file.txt");
    print_students("file.txt");

    print_students_by_grade(6.00f, "file.txt");

    return 0;
}