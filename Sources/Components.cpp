#include "..\Headers\Components.h"

/* Struct operator overloading */

template <typename Type>
bool operator!=(const Type &typeA, const Type &typeB) {
    return !(typeA == typeB);
}

bool operator==(const Date &dateA, const Date &dateB) {
    if(dateA.day != dateB.day) return false;
    if(dateA.month != dateB.month) return false;
    if(dateA.year != dateB.year) return false;

    return true;
}

bool operator==(const Name &nameA, const Name &nameB) {
    if(nameA.first != nameB.first) return false;
    if(nameA.last != nameB.last) return false;
    return true;
}

bool operator==(const User &userA, const User &userB) {
    if(userA.ID != userB.ID) return false;
    if(userA.name != userB.name) return false;
    return true;
}

bool operator==(const Staff &staffA, const Staff &staffB) {
    if(staffA.ID != staffB.ID) return false;
    if(staffA.name != staffB.name) return false;
    return true;
}

bool operator==(const Student &studentA, const Student &studentB) {
    if(studentA.ID != studentB.ID) return false;
    if(studentA.name != studentB.name) return false;
    if(studentA.socialID != studentB.socialID) return false;

    return true;
}

bool operator==(const AcademicYear &yearA, const AcademicYear &yearB) {
    if(yearA.start != yearB.start) return false;
    return true;
}

bool operator==(const Semester &semA, const Semester &semB) {
    if(semA.startDate != semB.startDate) return false;
    if(semA.endDate != semB.endDate) return false;
    return true;
}

bool operator==(const Course &courseA, const Course &courseB) {
    if(courseA.ID != courseB.ID) return false;
    if(courseA.classID != courseB.classID) return false;
    return true;
}

bool operator==(const SchoolYear &yearA, const SchoolYear &yearB) {
    if(yearA.start != yearB.start) return false;
    return true;
}

bool operator==(const Class &classA, const Class &classB) {
    if(classA.name != classB.name) return false;
    return true;
}

bool operator==(const Scoreboard &boardA, const Scoreboard &boardB) {
    if(boardA.ptrCourse != boardB.ptrCourse) return false;
    if(boardA.ptrStudent != boardB.ptrStudent) return false;
    return true;
}

/* Task functions */

// -> Start coding functions from here <-