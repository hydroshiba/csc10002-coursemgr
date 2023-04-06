#include "AcademicYear.h"

AcademicYear::AcademicYear(const unsigned int& start, Vector<Semester> semesters) {
    this->start = start;
    this->semesters = semesters;
}

void AcademicYear::addSemester(Semester& semester) {
    semesters.append(semester);
}

void AcademicYear::removeSemester(Semester& semester) {
    semesters.remove(semester);
}

std::string AcademicYear::getPeriod() {
    return std::to_string(start) + " - " + std::to_string(start + 1);
}

bool operator==(const AcademicYear& yearA, const AcademicYear& yearB) {
    if (yearA.start != yearB.start) return false;
    return true;
}