#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "Structures.h"

struct Date;
struct Year;
struct Semester;
struct Course;

struct User;
struct Class;
struct GPA;

struct Date {
    unsigned short day, month;
    unsigned int year;
};

struct Year {
    
};

struct GPA {
    float midterm = 0.0;
    float final = 0.0;
    float other = 0.0;
    float total = 0.0;

    Course* course;
};

struct User {
    std::string name, userID;
    std::string password;

    Date birthdate;
    bool gender;
};

struct Staff : User {

};

struct Student : User {

};

struct Course {
    std::string name, id, className;
    std::string instructor, weekday;
    int credits, maxStudents = 50;

    List<Student*> students;
};

struct Class {
    std::string name;
    Student student;
};

#endif