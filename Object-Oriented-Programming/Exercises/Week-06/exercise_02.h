// Напишете клас GradeReport, който съдържа следните полета:

// масив от оценки (точки в интервала от 0 до 100) с произволна дължина
// дължина на масива
// име на репорта - низ с произволна дължина
// Класът трябва съдържа следните методи:

// връща брой оценки в репорта
// връща името на репорта
// връща средния резултат
// статична функция merge(const GradeReport& a, const GradeReport& b),
//  която приема два GradeReport обекта и връща нов GradeReport, съдържащ всички 
// оценки от двата репорта. Името на новия репорт трябва да бъде конкатенация на 
// имената на двата (например "Клас А + Клас Б").
#include <iostream>

class GradeReport {
private:
    float* grades = nullptr;
    size_t gradesCount = 0;
    size_t gradesCapacity = 0;
    char* reportName = nullptr;

    void free();
    void resize(const size_t newGradesCapacity);
    void copyFrom(const GradeReport& other);
    void moveTo(GradeReport&& other) noexcept;

public:
    GradeReport();
    GradeReport(const GradeReport& other);
    GradeReport(GradeReport&& other) noexcept;
    GradeReport& operator = (const GradeReport& other);
    GradeReport& operator = (GradeReport&& other) noexcept;
    ~GradeReport();

    const char* getReportName() const;
    float getAvarageGrade() const;
    size_t getCountOfGrades() const;
    void addGrade(const float newGrade);
    
    static GradeReport merge(const GradeReport& left, const GradeReport& right);
    friend std::ostream& operator << (std::ostream& os, const GradeReport& report);
};