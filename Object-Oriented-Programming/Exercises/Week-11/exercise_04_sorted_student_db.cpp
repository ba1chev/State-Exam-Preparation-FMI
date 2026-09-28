#include "exercise_04_sorted_student_db.h"

void SortedStudentDB::sortBy(SortingCriteria criteria) {
    for (size_t i = 0; i < this->size - 1; i++) {
        for (size_t j = 0; j < this->size - i - 1; j++) {
            if (criteria(this->data[j], this->data[j + 1])) {
                Student temp = this->data[j];
                this->data[j] = this->data[j + 1];
                this->data[j + 1] = temp;
            }
        }
    }
}