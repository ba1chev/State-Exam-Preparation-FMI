#include "exercise_04_student_db.h"

void StudentDB::free() {
    delete[] this->data;
    this->data = nullptr;
    this->size = 0;
    this->capacity = 0;
}

void StudentDB::resize(const size_t newCapacity) {
    if (newCapacity <= this->capacity) {
        throw std::runtime_error("New capacity must be greater");
    }

    this->capacity = newCapacity;
    Student* newData = new Student[this->capacity]{};
    for (size_t i = 0; i < this->size; i++) {
        newData[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newData;
}

void StudentDB::copyFrom(const StudentDB& other) {
    this->data = new Student[other.capacity]{};
    this->capacity = other.capacity;
    this->size = other.size;
    for (size_t i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];   
    }
}

void StudentDB::moveTo(StudentDB&& other) noexcept {
    this->data = other.data;
    this->size = other.size;
    this->capacity = other.capacity;

    other.data = nullptr;
    other.size = 0;
    other.capacity = 0;
}

StudentDB::StudentDB() {
    this->size = 0;
    this->capacity = 8;
    this->data = new Student[this->capacity]{};
}

StudentDB::StudentDB(const StudentDB& other) {
    this->copyFrom(other);
}

StudentDB::StudentDB(StudentDB&& other) noexcept {
    this->moveTo(std::move(other));
}

StudentDB& StudentDB::operator = (const StudentDB& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}

StudentDB& StudentDB::operator = (StudentDB&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}

StudentDB::~StudentDB() {
    this->free();
}

void StudentDB::add(const Student& student) {
    if (this->size == this->capacity) {
        this->resize(this->size * 2);
    }
    this->data[this->size] = student;
    this->size += 1;
}
    
void StudentDB::remove(const char* fnId) {
    if (!fnId) {
        throw std::runtime_error("Nullptr detected");
    }

    int foundIndex = -1;
    for (size_t i = 0; i < this->size; i++) {
        if (!strcmp(this->data[i].getFnId(), fnId)) {
            foundIndex = i;
            break;
        }
    }
    
    if (foundIndex != -1) {
        for (size_t i = foundIndex; i < size - 1; i++) {
            this->data[i] = this->data[i + 1];
        }
        this->size -= 1;
    }
}
    
const Student& StudentDB::findStudent(const char* fnId) const {
    if (!fnId) {
        throw std::runtime_error("Nullptr detected");
    }

    for (size_t i = 0; i < this->size; i++) {
        if (!strcmp(this->data[i].getFnId(), fnId)) {
            return this->data[i];
        }
    }
    throw std::runtime_error("Not found");
}
    
void StudentDB::display() const {
    for (size_t i = 0; i < this->size; i++) {
        this->data[i].printMethod();   
    }
}