#ifndef ACADEMIC_YEAR_H
#define ACADEMIC_YEAR_H

#include "Components.h"
#include "Semester.h"

struct AcademicYear {
    unsigned int start;
    Vector<Semester> semesters;

    AcademicYear(const unsigned int& start = 0, const Vector<Semester>& semester = Vector<Semester>());

    Semester* getSemester(const std::string& semesterID);

    void addSemester(Semester& semester);

    void removeSemester(Semester& semester);

    void removeAllSemester();

    std::string getPeriod() const;
};

bool operator==(const AcademicYear& yearA, const AcademicYear& yearB);

#endif