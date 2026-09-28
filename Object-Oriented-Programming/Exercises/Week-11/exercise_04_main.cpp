// Създайте клас Student, който съдържа следната информация:

// име
// факултетен номер (от тип unsigned); уникален идентификатор
// курс, в който учи
// Да се реализира клас StudentDB, който представлява база от данни за съхранение на информацията за студенти. Класът да поддържа следните функционалности:

// add - добавяне студент в базата
// remove - премахване на студент от базата по подаден факултетен номер
// find - търсене на студент в базата по подаден факултетен номер
// display - визуализира информация за базата данни
// Да се реализира клас SortedStudentDB, който наследява StudentDB и поддържа следната допълнителна функционалност:

// sortBy - запазва студентите сортирани по подаден критерий
// Да се реализира клас FilteredStudentDB, който наследява StudentDB и поддържа следните допълнителни функционалности:

// filter - по подаден критерий запазва в базата данни само студентите, които го изпълняват
// limit - по подаден брой N запазва само първите N студенти в базата
#include <iostream>
#include "exercise_04_sorted_student_db.h"
#include "exercise_04_filtered_student_db.h"

bool byAgeAscending(const Student& lhs, const Student& rhs) {
    return lhs.getAge() > rhs.getAge();
}

bool isAdult(const Student& student) {
    return student.getAge() >= 18;
}

int main() {
    StudentDB db;
    db.add(Student("Ivan", "0MI0600001", 20));
    db.add(Student("Maria", "0MI0600002", 22));
    db.add(Student("Petar", "0MI0600003", 19));

    std::cout << "===== StudentDB =====" << std::endl;
    db.display();

    std::cout << "===== find 0MI0600002 =====" << std::endl;
    db.findStudent("0MI0600002").printMethod();

    db.remove("0MI0600001");
    std::cout << "===== after remove 0MI0600001 =====" << std::endl;
    db.display();

    SortedStudentDB sorted;
    sorted.add(Student("Ivan", "0MI0600001", 20));
    sorted.add(Student("Maria", "0MI0600002", 22));
    sorted.add(Student("Petar", "0MI0600003", 19));
    sorted.sortBy(byAgeAscending);
    std::cout << "===== SortedStudentDB by age =====" << std::endl;
    sorted.display();

    FilteredStudentDB filtered;
    filtered.add(Student("Ivan", "0MI0600001", 20));
    filtered.add(Student("Kids", "0MI0600004", 15));
    filtered.add(Student("Maria", "0MI0600002", 22));
    filtered.filter(isAdult);
    std::cout << "===== FilteredStudentDB adults only =====" << std::endl;
    filtered.display();

    filtered.limit(1);
    std::cout << "===== FilteredStudentDB limit 1 =====" << std::endl;
    filtered.display();

    return 0;
}