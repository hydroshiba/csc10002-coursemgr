#ifndef SEMESTER_H
#define SEMESTER_H

#include "Components.h"
#include "Date.h"

struct Semester {
    Date startDate, endDate;
    Vector<Course> courses;
    AcademicYear* year = nullptr;

    void addCourse(const Course& newCourse) {
        courses.append(newCourse);
    }

    void removeCourse(const Course& newCourse) {
        courses.remove(newCourse);
    }
};

#endif 

