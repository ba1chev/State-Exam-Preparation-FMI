#include "exercise_02.h"

int main() {
    GradeReport reportA;
    reportA.addGrade(90);
    reportA.addGrade(80);
    reportA.addGrade(100);

    GradeReport reportB;
    reportB.addGrade(50);
    reportB.addGrade(60);

    std::cout << reportA << std::endl;
    std::cout << reportB << std::endl;

    std::cout << reportA.getReportName() << std::endl;
    std::cout << reportA.getCountOfGrades() << std::endl;
    std::cout << reportA.getAvarageGrade() << std::endl;

    GradeReport merged = GradeReport::merge(reportA, reportB);
    std::cout << merged << std::endl;
    std::cout << merged.getReportName() << std::endl;
    std::cout << merged.getCountOfGrades() << std::endl;
    std::cout << merged.getAvarageGrade() << std::endl;

    return 0;
}