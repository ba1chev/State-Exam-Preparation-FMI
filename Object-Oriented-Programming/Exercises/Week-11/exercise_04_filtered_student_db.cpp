#include "exercise_04_filtered_student_db.h"

void FilteredStudentDB::filter(FilteringCriteria criteria) {
    for (size_t i = 0; i < this->size;) {
        if (!criteria(this->data[i])) {
            this->remove(this->data[i].getFnId());
        } else {
            i++;
        }
    }
}

void FilteredStudentDB::limit(const size_t N) {
    if (N >= this->size) {
        return;
    }

    while (this->size > N) {
        this->remove(this->data[this->size - 1].getFnId());
    }
}