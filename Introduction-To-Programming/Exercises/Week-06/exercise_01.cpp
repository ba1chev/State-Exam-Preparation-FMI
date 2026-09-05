// Да се състави програма, която въвежда оценките на един ученик и 
// пресмята средния му успех. Първо да се въведе броят на оценките, 
// а след това и самите оценки разделени с интервал. В масива може да 
// има най-много 50 елемента.
#include <iostream>

int main() {
    int count_of_grades = 0;
    int grades[50]{};
    int sum_of_grades = 0;
    std::cin >> count_of_grades;
    if (count_of_grades < 0 || count_of_grades > 50) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    for (size_t i = 0; i < count_of_grades; i++) {
        std::cin >> grades[i];
        sum_of_grades += grades[i];
    }
    
    float result = (sum_of_grades / (count_of_grades + 0.0f));
    std::cout << result << std::endl;
    return 0;
}