#ifndef COURSE_H
#define COURSE_H

#include "Components.h"

#include "Scoreboard.h"
#include "Student.h"

struct Course {
    std::string ID, classID;
    std::string name, teacher;

    int credits, maxEnroll = 50;
    Weekday weekday;
    Session session;

    Semester* ptrSemester = nullptr;
    Vector<Scoreboard*> scoreboards;

    void addStudent(Student& student);

    void removeStudent(Student& student);

    Scoreboard* getScoreboard(Student& student);
    
    void display(std::ostream& outDev);

    void displayScreen();

    void displayCSVFile(std::ostream& ofs);
};

bool operator==(const Course& courseA, const Course& courseB);

#endif // !COURSE_H