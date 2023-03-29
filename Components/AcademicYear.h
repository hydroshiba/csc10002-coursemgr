#ifndef ACADEMIC_YEAR_H
#define ACADEMIC_YEAR_H

#include "Components.h"
#include "Semester.h"

struct AcademicYear {
    unsigned int start;
    Vector<Semester> semesters;

    void addSemester(const Semester& newSemester);

    void removeSemester(const Semester& newSemester);

    std::string getPeriod();
};

bool operator==(const AcademicYear& yearA, const AcademicYear& yearB);

#endif