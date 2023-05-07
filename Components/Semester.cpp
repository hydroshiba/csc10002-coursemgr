#include "Semester.h"

Semester::Semester(const std::string& semesterID, const Date& startDate, const Date& endDate, const Vector<Course>& course, AcademicYear* ptrAcademicYear) {
    this->semesterID = semesterID;
    this->startDate = startDate;
    this->endDate = endDate;
    this->courses = course;
    this->ptrAcademicYear = ptrAcademicYear;
}

void Semester::set(const std::string& semesterID, const Date& startDate, const Date& endDate, const Vector<Course>& course, AcademicYear* ptrAcademicYear) {
    this->semesterID = semesterID;
    this->startDate = startDate;
    this->endDate = endDate;
    this->courses = course;
    this->ptrAcademicYear = ptrAcademicYear;
}

void Semester::updateSemesterID(const std::string& semesterID) {
    this->semesterID = semesterID;
}

void Semester::updateStartDate(const Date& startDate) {
    this->startDate = startDate;
}

void Semester::updateEndDate(const Date& endDate) {
    this->endDate = endDate;
}

void Semester::updateCourses(Vector<Course>& course) {
    this->courses = course;
}

void Semester::updateAcademicYear(AcademicYear* ptrAcademicYear) {
    this->ptrAcademicYear = ptrAcademicYear;
}

Course* Semester::getCourse(const std::string& courseID) {
    Course* ptrCourse = nullptr;
    for (int i = 0; i < courses.size(); i++)
        if (courses[i].ID == courseID)
        {
            ptrCourse = &courses[i];
            break;
        }
    return ptrCourse;
}

void Semester::addCourse(Course& course) {
    course.ptrSemester = this;
    courses.append(course);    
}

void Semester::removeCourse(Course& course) {
    courses.remove(course);
    course.ptrSemester = nullptr;
}

void Semester::removeAllCourse() {
    if (courses.size() == 0)
        return;
    for (int i = 0; i < courses.size(); i++) {
        courses[i].removeAllStudent();
    }
    courses.resize(0);
}
bool operator==(const Semester& semA, const Semester& semB) {
    if (semA.semesterID != semB.semesterID) return false;
    if (semA.startDate != semB.startDate) return false;
    if (semA.endDate != semB.endDate) return false;
    return true;
}