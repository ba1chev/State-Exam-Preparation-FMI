// Създайте програма, която позволява създаване на студенти и преподаватели,
// както и преподаване на различни предмети на студентите. Студентите се 
// идентифицират чрез уникален факултетен номер, но също така имат име и възраст.
// Преподавателите също имат име и възраст, както и списък от предмети, които могат да преподават.
#include <iostream>
#include "exercise_01_student.h"
#include "exercise_01_teacher.h"

int main() {
    Human* student = new Student("Yoan Baychev", "0MI0600328", 22);
    Teacher* teacher = new Teacher("Magi Dicheva", 21);
    teacher->addSubject("Math");
    teacher->addSubject("Psychology");
    student->printMethod();
    teacher->printMethod();

    delete student;
    delete teacher;
    student = nullptr;
    teacher = nullptr;
    return 0;
}