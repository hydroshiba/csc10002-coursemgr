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

    void addCourse(const Course& newCourse);

    void removeCourse(const Course& newCourse);
};

bool operator==(const Semester& semA, const Semester& semB);
#endif