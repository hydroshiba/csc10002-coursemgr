#include "AcademicYear.h"

void AcademicYear::addSemester(const Semester& newSemester) {
    semesters.append(newSemester);
}

void AcademicYear::removeSemester(const Semester& newSemester) {
    semesters.remove(newSemester);
}

std::string AcademicYear::getPeriod() {
    return std::to_string(start) + " - " + std::to_string(start + 1);
}

bool operator==(const AcademicYear& yearA, const AcademicYear& yearB) {
    if (yearA.start != yearB.start) return false;
    return true;
}