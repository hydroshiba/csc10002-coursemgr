#include "Semester.h"

void Semester::addCourse(const Course& newCourse) {
    courses.append(newCourse);
}

void Semester::removeCourse(const Course& newCourse) {
    courses.remove(newCourse);
}

bool operator==(const Semester& semA, const Semester& semB) {
    if (semA.startDate != semB.startDate) return false;
    if (semA.endDate != semB.endDate) return false;
    return true;
}