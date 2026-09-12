// Реализирайте система за управление на студенти:

// Структура/клас Student със следните член-данни:

// име (дължина до 32 символа)
// факултетен номер (число с точно 6 цифри)
// среден успех (реално число)
// специалност (enum class със специалности във ФМИ)
// Структура/клас Course със следните член-данни:

// масив от студенти (най-много 50)
// брой студнети
// Реализирайте следните функии:

// Приема име, ФН и специалност и създава студент.
// Извежда данните за даден студент на стандартния изход.
// Извежда данните за студентите в даден курс на стандартния изход.
// Приема курс и студент и добавя студента към курса. При достигната максимална 
// бройка студенти в курса да не го добавя.
// Приема курс и ФН и премахва студента с този ФН от курса.
// Приема курс и указател към функция унарен предикат, приемаща студент. 
// Функцията филтрира всички студенти от курса и извежда данните само на тези, за 
// които предиката дава true.
// Приема курс и сортира студентите по подаден бинарен предикат.
#include <iostream>
#include <cstring>

enum class Speciality {
    SI, KN, IS, INF, AD
};
 
class Student {
private:
    char name[32 + 1] = "";
    char fnId[6 + 1] = "";
    float avarageGrade = 6.0f;
    Speciality speciality = Speciality::SI;

public:
    Student() = default;
    
    Student(const char* name, const char* fnId, const float avarageGrade,
        Speciality speciality) {
        if (!name || !fnId || strlen(name) > 32 || strlen(fnId) > 6) {
            throw std::runtime_error("Invalid input");
        }

        strncpy(this->name, name, 32);
        strncpy(this->fnId, fnId, 6);
        this->avarageGrade = avarageGrade;
        this->speciality = speciality;
    }

    const char* getName() const {
        return this->name;
    }

    const char* getFnId() const {
        return this->fnId;
    }

    float getAvarageGrade() const {
        return this->avarageGrade;
    }

    Speciality getSpeciality() const {
        return this->speciality;
    }

    void print() const {
        std::cout << this->name << " ";
        std::cout << this->fnId << " ";
        std::cout << this->avarageGrade << " ";
        
        switch (this->speciality) {
            case Speciality::SI: {
                std::cout << "SI" << std::endl;
                break;
            }
            case Speciality::KN: {
                std::cout << "KN" << std::endl;
                break;
            }
            case Speciality::IS: {
                std::cout << "IS" << std::endl;
                break;
            }
            case Speciality::INF: {
                std::cout << "INF" << std::endl;
                break;
            }
            case Speciality::AD: {
                std::cout << "AD" << std::endl;
                break;
            }
            default: {
                throw std::runtime_error("Not supported speciality");
            }
        }
    }
};

class Course {
private:
    Student students[50]{};
    size_t countOfStudents = 0;

public:
    Course() = default;

    void addStudent(const Student& student) {
        if (this->countOfStudents >= 50) {
            return;
        }

        this->students[this->countOfStudents] = student;
        this->countOfStudents += 1;
    }

    void printStudent() const {
        for (size_t i = 0; i < this->countOfStudents; i++) {
            this->students[i].print();
        }
    }

    void removeStudent(const char* fnId) {
        if (!fnId) {
            throw std::runtime_error("Nullptr detected");
        }

        int foundIndex = -1;
        for (size_t i = 0; i < this->countOfStudents; i++) {
            if (!strcmp(this->students[i].getFnId(), fnId)) {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1) {
            for (size_t i = foundIndex; i < this->countOfStudents - 1; i++) {
                this->students[i] = this->students[i + 1];
            }
            this->countOfStudents -= 1;
        }
    }

    const Student& getStudent(size_t index) const {
        if (index >= this->countOfStudents) {
            throw std::out_of_range("Out of range");
        }
        return this->students[index];
    }

    Student& getStudent(size_t index) {
        if (index >= this->countOfStudents) {
            throw std::out_of_range("Out of range");
        }
        return this->students[index];
    }

    size_t getCountOfStudents() const {
        return this->countOfStudents;
    }
};

typedef bool (*Predicate)(const Student&);
void filterStudents(Course* course, Predicate predicate) {
    if (!course || !predicate) {
        throw std::runtime_error("Nullptr detected");
    }

    for (size_t i = 0; i < course->getCountOfStudents(); i++) {
        const Student& currentStudent = course->getStudent(i);
        if (predicate(currentStudent)) {
            currentStudent.print();
        }
    }
}

typedef bool (*SortingPredicate)(const Student&, const Student&);
void sortCourse(Course& course, SortingPredicate predicate) {
    for (size_t i = 0; i + 1 < course.getCountOfStudents(); i++) {
        for (size_t j = 0; j + 1 < course.getCountOfStudents() - i; j++) {
            if (predicate(course.getStudent(j), course.getStudent(j + 1))) {
                Student temp = course.getStudent(j);
                course.getStudent(j) = course.getStudent(j + 1);
                course.getStudent(j + 1) = temp;
            }
        }
    }
}

bool isExcellent(const Student& student) {
    return student.getAvarageGrade() >= 5.50f;
}

bool byGradeDescending(const Student& left, const Student& right) {
    return left.getAvarageGrade() < right.getAvarageGrade();
}

int main() {
    Course course;
    course.addStudent(Student("Ivan", "100001", 5.75f, Speciality::SI));
    course.addStudent(Student("Maria", "100002", 4.20f, Speciality::KN));
    course.addStudent(Student("Petar", "100003", 5.90f, Speciality::IS));

    std::cout << "All students:" << std::endl;
    course.printStudent();

    std::cout << "After removing 100002:" << std::endl;
    course.removeStudent("100002");
    course.printStudent();

    std::cout << "Excellent students (>= 5.50):" << std::endl;
    filterStudents(&course, isExcellent);

    std::cout << "Sorted by grade descending:" << std::endl;
    sortCourse(course, byGradeDescending);
    course.printStudent();

    return 0;
}