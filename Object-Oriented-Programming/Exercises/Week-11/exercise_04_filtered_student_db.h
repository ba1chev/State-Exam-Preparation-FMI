#pragma once
#include "exercise_04_student_db.h"

class FilteredStudentDB: public StudentDB {
public:
    typedef bool (*FilteringCriteria)(const Student&);
    void filter(FilteringCriteria criteria);
    void limit(const size_t N);
};