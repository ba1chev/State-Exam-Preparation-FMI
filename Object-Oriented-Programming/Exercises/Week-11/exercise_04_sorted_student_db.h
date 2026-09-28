#pragma once
#include "exercise_04_student_db.h"

class SortedStudentDB: public StudentDB {
public:
    typedef bool (*SortingCriteria)(const Student&, const Student&);
    void sortBy(SortingCriteria criteria);
};