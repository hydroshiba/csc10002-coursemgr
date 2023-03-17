#ifndef ACADEMIC_YEAR_H
#define ACADEMIC_YEAR_H

#include "Components.h"

struct AcademicYear {
    unsigned int start;
    Vector<Semester> semesters;

    void addSemester(const Semester& newSemester) {
        semesters.append(newSemester);
    }

    void removeSemester(const Semester& newSemester) {
        semesters.remove(newSemester);
    }

    std::string getPeriod() {
        return std::to_string(start) + " - " + std::to_string(start + 1);
    }
};

#endif 

