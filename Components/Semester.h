#ifndef SEMESTER_H
#define SEMESTER_H

#include "Components.h"

#include "Course.h"
#include "Date.h"

struct Semester {
    std::string semesterID;
    Date startDate, endDate;
    Vector<Course> courses;
    AcademicYear* ptrAcademicYear;

    Semester(const std::string semesterID = "\n", const Date& startDate = { 0, 0, 0 }, const Date& endDate = { 0, 0, 0 }, Vector<Course> course = Vector<Course>(), AcademicYear* ptrAcademicYear = nullptr);

    void addCourse(Course& course);

    void removeCourse(Course& course);
};

bool operator==(const Semester& semA, const Semester& semB);
#endif