#ifndef COURSE_H
#define COURSE_H

#include "Components.h"

#include "Scoreboard.h"
#include "Student.h"
#include "Semester.h"
struct Course {
    std::string ID, classID;
    std::string name, teacher;

    int credits, maxEnroll = 50;
    Weekday weekday;
    Session session;

    Semester* ptrSemester = nullptr;
    Vector<Scoreboard*> scoreboards;
    void addStudent(Student& student);  
    // already set double linke between Course & Score, Score & Student
    void removeStudent(Student& student);

    Scoreboard* getScoreboard(Student& student);
    
    void displayInfo(std::ostream& outDev);

    void displayInfoScreen();

    void displayInfoFile(std::ostream& ofs);

    void importScoreBoards(std::ifstream& ifs);

    void displayScoreBoards(std::ostream& outDev = std::cout);

    void displayScoreBoardFile(std::ostream& outDev);

    void displayScoreBoardScreen();
};

bool operator==(const Course& courseA, const Course& courseB);

#endif // !COURSE_H