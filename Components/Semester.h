#ifndef SEMESTER_H
#define SEMESTER_H

#include "Components.h"

#include "Course.h"
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

bool operator==(const Semester &semA, const Semester &semB) {
    if(semA.startDate != semB.startDate) return false;
    if(semA.endDate != semB.endDate) return false;
    return true;
}

#endif