#include "AcademicYear.h"

AcademicYear::AcademicYear(const unsigned int& start, const Vector<Semester>& semesters) {
    this->start = start;
    this->semesters = semesters;
}

Semester* AcademicYear::getSemester(const std::string& semesterID) {
    Semester* ptrSemester = nullptr;
    for (int i = 0; i < semesters.size(); i++)
        if (semesters[i].semesterID == semesterID)
        {
            ptrSemester = &semesters[i];
            break;
        }
    return nullptr;
}

void AcademicYear::addSemester(Semester& semester) {
    semesters.append(semester);
    semester.ptrAcademicYear = this;
}

void AcademicYear::removeSemester(Semester& semester) {
    semesters.remove(semester);
    semester.ptrAcademicYear = nullptr;
}

void AcademicYear::removeAllSemester() {
    for (int i = 0; i < semesters.size(); i++) {
        semesters[i].removeAllCourse();
    }
    semesters.resize(0);
}

std::string AcademicYear::getPeriod() const{
    return std::to_string(start) + " - " + std::to_string(start + 1);
}

bool operator==(const AcademicYear& yearA, const AcademicYear& yearB) {
    if (yearA.start != yearB.start) 
        return false;
    return true;
}