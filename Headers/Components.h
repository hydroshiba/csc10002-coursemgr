#ifndef COMPONENT_H
#define COMPONENT_H

struct Year;
struct Semester;
struct Course;

struct Student;
struct Class;
struct GPA;

struct Student {

};

struct Course {

};

struct GPA {
    float midterm = 0.0;
    float final = 0.0;
    float other = 0.0;
    float total = 0.0;

    Student* student;
    Course* course;
};

#endif