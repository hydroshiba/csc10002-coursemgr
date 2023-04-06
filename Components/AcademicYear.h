#ifndef ACADEMIC_YEAR_H
#define ACADEMIC_YEAR_H

#include "Components.h"
#include "Semester.h"

struct AcademicYear {
    unsigned int start;
    Vector<Semester> semesters;

    AcademicYear(const unsigned int& start = 0, Vector<Semester> semester = Vector<Semester>());

    void addSemester(Semester& semester);

    void removeSemester(Semester& semester);

    std::string getPeriod();
};

bool operator==(const AcademicYear& yearA, const AcademicYear& yearB);

#endif