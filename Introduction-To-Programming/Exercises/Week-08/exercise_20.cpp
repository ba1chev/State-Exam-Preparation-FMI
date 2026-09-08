// За учениците от десети клас в училище се съхранява следната информация:
// име, фамилия,извинени и неизвинени отсъствия. Да се напише програма,
// която:
//създава файл съдържащ информация за учениците;
// извежда съдържанието на файла;
// намира общия брой извинени и неизвинени отсъствия;
// намира името/-ната на ученика/-ците с най-много неизвинени отсъствия;
// по въведено име на ученик - извежда информацията за него;
// сортира по име във възходящ ред въведените данни;
// по въведено име на ученик - изтрива данните за него
// по въведено име на ученик - актуализира данните за него.
#include <iostream>
#include <fstream>

struct Student {
public:
    char first_name[100];
    char last_name[100];
    int excused_absences = 0;
    int non_excused_absences = 0;
};

void write_student_to_file(std::ofstream& ofs, const Student& student) {
    if (!ofs.is_open()) {
        std::cout << "File cannot open" << std::endl;
        return;
    }

    ofs << student.first_name << " " << student.last_name << " ";
    ofs << student.non_excused_absences << " " << student.excused_absences << std::endl;
}

void write_students_to_file(std::ofstream& ofs, const Student* students, int size) {
    if (!ofs.is_open() || !students || size < 0) {
        std::cout << "File cannot open or invalid function input" << std::endl;
        return;
    }

    ofs << size << std::endl;
    for (size_t i = 0; i < size; i++) {
        write_student_to_file(ofs, students[i]);
    }
}

void print_student(const Student& student) {
    std::cout << student.first_name << " " << student.last_name << " "
        << student.excused_absences << " " << student.non_excused_absences << std::endl;
}

void read_students_from_file(std::ifstream& ifs, Student* students, int& size) {
    if (!ifs.is_open() || !students) {
        std::cout << "File cannot open or invalid function input" << std::endl;
        size = 0;
        return;
    }

    ifs >> size;
    ifs.ignore(1);
    for (size_t i = 0; i < size; i++) {
        ifs >> students[i].first_name;
        ifs >> students[i].last_name;
        ifs >> students[i].non_excused_absences;
        ifs >> students[i].excused_absences;
        ifs.ignore(1);
    }
}

void print_students(const Student* students, int size) {
    if (!students || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < size; i++) {
        print_student(students[i]);
    }
}

void find_total_absences(const Student* students, int size) {
    if (!students || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int total_excused = 0;
    int total_non_excused = 0;
    for (size_t i = 0; i < size; i++) {
        total_excused += students[i].excused_absences;
        total_non_excused += students[i].non_excused_absences;
    }

    std::cout << "Total excused: " << total_excused << " ";
    std::cout << "Total non-excused: " << total_non_excused << std::endl;
}

void find_most_non_excused(const Student* students, int size) {
    if (!students || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    int max_non_excused = 0;
    for (size_t i = 0; i < size; i++) {
        if (students[i].non_excused_absences > max_non_excused) {
            max_non_excused = students[i].non_excused_absences;
        }
    }

    for (size_t i = 0; i < size; i++) {
        if (students[i].non_excused_absences == max_non_excused) {
            std::cout << students[i].first_name << " " << students[i].last_name << std::endl;
        }
    }
}

void find_student_by_name(const Student* students, int size, const char* first_name) {
    if (!students || size < 0 || !first_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < size; i++) {
        if (strcmp(students[i].first_name, first_name) == 0) {
            print_student(students[i]);
            return;
        }
    }

    std::cout << "Student not found" << std::endl;
}

void sort_students_by_name(Student* students, int size) {
    if (!students || size < 0) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (strcmp(students[j].first_name, students[j + 1].first_name) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void delete_student_by_name(Student* students, int& size, const char* first_name) {
    if (!students || size < 0 || !first_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < size; i++) {
        if (strcmp(students[i].first_name, first_name) == 0) {
            for (size_t j = i; j < size - 1; j++) {
                students[j] = students[j + 1];
            }
            size -= 1;
            return;
        }
    }

    std::cout << "Student not found" << std::endl;
}

void update_student_by_name(Student* students, int size, const char* first_name,
        int excused_absences, int non_excused_absences) {
    if (!students || size < 0 || !first_name) {
        std::cout << "Invalid function input" << std::endl;
        return;
    }

    for (size_t i = 0; i < size; i++) {
        if (strcmp(students[i].first_name, first_name) == 0) {
            students[i].excused_absences = excused_absences;
            students[i].non_excused_absences = non_excused_absences;
            return;
        }
    }

    std::cout << "Student not found" << std::endl;
}

int main() {
    char first_name_1[5] = "Yoan";
    char first_name_2[6] = "Boris";
    char first_name_3[7] = "Daniel";
    char first_name_4[8] = "Andrian";
    char last_name_1[8] = "Baychev";
    char last_name_2[11] = "Vladimirov";
    char last_name_3[9] = "Georgiev";
    char last_name_4[7] = "Ivanov";

    Student s1;
    strncpy(s1.first_name, first_name_1, strlen(first_name_1));
    s1.first_name[strlen(first_name_1)] = '\0';
    strncpy(s1.last_name, last_name_1, strlen(last_name_1));
    s1.last_name[strlen(last_name_1)] = '\0';
    s1.excused_absences = 10;
    s1.non_excused_absences = 5;

    Student s2;
    strncpy(s2.first_name, first_name_2, strlen(first_name_2));
    s2.first_name[strlen(first_name_2)] = '\0';
    strncpy(s2.last_name, last_name_2, strlen(last_name_2));
    s2.last_name[strlen(last_name_2)] = '\0';
    s2.excused_absences = 10;
    s2.non_excused_absences = 8;

    Student s3;
    strncpy(s3.first_name, first_name_3, strlen(first_name_3));
    s3.first_name[strlen(first_name_3)] = '\0';
    strncpy(s3.last_name, last_name_3, strlen(last_name_3));
    s3.last_name[strlen(last_name_3)] = '\0';
    s3.excused_absences = 10;
    s3.non_excused_absences = 5;

    Student s4;
    strncpy(s4.first_name, first_name_4, strlen(first_name_4));
    s4.first_name[strlen(first_name_4)] = '\0';
    strncpy(s4.last_name, last_name_4, strlen(last_name_4));
    s4.last_name[strlen(last_name_4)] = '\0';
    s4.excused_absences = 10;
    s4.non_excused_absences = 8;

    Student students[4] = {s1, s2, s3, s4};
    std::ofstream ofs("file.txt");
    write_students_to_file(ofs, students, 4);
    ofs.close();

    Student read_students[100];
    int size = 0;
    std::ifstream ifs("file.txt");
    read_students_from_file(ifs, read_students, size);
    ifs.close();

    std::cout << "All students:" << std::endl;
    print_students(read_students, size);

    find_total_absences(read_students, size);

    std::cout << "Most non-excused absences:" << std::endl;
    find_most_non_excused(read_students, size);

    std::cout << "Search Boris:" << std::endl;
    find_student_by_name(read_students, size, "Boris");

    sort_students_by_name(read_students, size);
    std::cout << "Sorted by name:" << std::endl;
    print_students(read_students, size);

    update_student_by_name(read_students, size, "Yoan", 3, 0);
    std::cout << "After updating Yoan:" << std::endl;
    print_students(read_students, size);

    delete_student_by_name(read_students, size, "Daniel");
    std::cout << "After deleting Daniel:" << std::endl;
    print_students(read_students, size);

    return 0;
}
