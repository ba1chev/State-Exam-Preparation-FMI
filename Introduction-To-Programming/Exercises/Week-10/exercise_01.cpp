// Да се състави програма, която въвежда оценките на един ученик и 
// пресмята средния му успех. Първо да се въведе броят на оценките, а 
// след това и самите оценки разделени с интервал.
#include <iostream>

int main() {
    int grades_count = 0;
    std::cin >> grades_count;
    if (grades_count < 0) {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    float* grades = new float[grades_count]{};
    float grades_sum = 0.0f;
    for (size_t i = 0; i < grades_count; i++) {
        std::cin >> grades[i];
        grades_sum += grades[i];
    }
    
    std::cout << (grades_sum / (grades_count + 0.0f)) << std::endl;
    delete[] grades;
    grades = nullptr;
    return 0;
}
