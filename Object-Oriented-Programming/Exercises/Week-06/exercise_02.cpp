#include <iostream>
#include <cstring>

#include "exercise_02.h"
    
void GradeReport::free() {
    delete[] this->grades;
    delete[] this->reportName;
    this->grades = nullptr;
    this->reportName = nullptr;
    this->gradesCapacity = 0;
    this->gradesCount = 0;
}
    
void GradeReport::resize(const size_t newGradesCapacity) {
    if (newGradesCapacity <= this->gradesCapacity) {
        throw std::runtime_error("Invalid input");
    }

    float* newGrades = new float[newGradesCapacity]{};
    std::memcpy(newGrades, this->grades, this->gradesCapacity * sizeof(float));
    delete[] this->grades;
    this->grades = newGrades;
    this->gradesCapacity = newGradesCapacity;
}
    
void GradeReport::copyFrom(const GradeReport& other) {
    this->gradesCount = other.gradesCount;
    this->gradesCapacity = other.gradesCapacity;
    this->reportName = new char[strlen(other.reportName) + 1]{};
    strncpy(this->reportName, other.reportName, strlen(other.reportName));
    this->grades = new float[this->gradesCapacity]{};
    std::memcpy(this->grades, other.grades, this->gradesCount * sizeof(float));
}
    
void GradeReport::moveTo(GradeReport&& other) noexcept {
    this->grades = other.grades;
    this->reportName = other.reportName;
    this->gradesCount = other.gradesCount;
    this->gradesCapacity = other.gradesCapacity;

    other.grades = nullptr;
    other.reportName = nullptr;
    other.gradesCount = 0;
    other.gradesCapacity = 0;
}

GradeReport::GradeReport() {
    this->gradesCount = 0;
    this->gradesCapacity = 8;
    this->grades = new float[this->gradesCapacity]{0};
    this->reportName = new char[8 + 1]{};
    strncpy(this->reportName, "default", strlen("default"));
}
    
GradeReport::GradeReport(const GradeReport& other) {
    this->copyFrom(other);
}
    
GradeReport::GradeReport(GradeReport&& other) noexcept {
    this->moveTo(std::move(other));
}
    
GradeReport& GradeReport::operator = (const GradeReport& other) {
    if (this != &other) {
        this->free();
        this->copyFrom(other);
    }
    return *this;
}
    
GradeReport& GradeReport::operator = (GradeReport&& other) noexcept {
    if (this != &other) {
        this->free();
        this->moveTo(std::move(other));
    }
    return *this;
}
    
GradeReport::~GradeReport() {
    this->free();
}
    
const char* GradeReport::getReportName() const {
    return this->reportName;
}
    
float GradeReport::getAvarageGrade() const {
    float result = 0.0f;
    for (size_t i = 0; i < this->gradesCount; i++) {
        result += this->grades[i];
    }
    return result / (this->gradesCount + 0.0f);
}
    
size_t GradeReport::getCountOfGrades() const {
    return this->gradesCount;
}

void GradeReport::addGrade(const float newGrade) {
    if (newGrade < 0 || newGrade > 100) {
        throw std::runtime_error("Invalid input");
    }

    if (this->gradesCount == this->gradesCapacity) {
        this->resize(this->gradesCapacity * 2);
    }

    this->grades[this->gradesCount] = newGrade;
    this->gradesCount += 1;
}

std::ostream& operator << (std::ostream& os, const GradeReport& report) {
    os << report.reportName << " " << "[ ";
    for (size_t i = 0; i < report.gradesCount; i++) {
        os << report.grades[i] << " ";
    }
    os << "]";
    return os;
}

GradeReport GradeReport::merge(const GradeReport& left, const GradeReport& right) {
    GradeReport result = left;
    for (size_t i = 0; i < right.gradesCount; i++) {
        result.addGrade(right.grades[i]);
    }
    
    delete[] result.reportName;
    result.reportName = new char[strlen(left.reportName) + strlen(" + ") + strlen(right.reportName) + 1]{};

    char* strPtr = result.reportName;
    strncpy(strPtr, left.reportName, strlen(left.reportName));
    strPtr += strlen(left.reportName);
    strncpy(strPtr, " + ", strlen(" + "));
    strPtr += strlen(" + ");
    strncpy(strPtr, right.reportName, strlen(right.reportName));

    return result;
}