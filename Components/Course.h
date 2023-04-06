#ifndef COURSE_H
#define COURSE_H

#include "Components.h"

#include "Class.h"
#include "Scoreboard.h"
#include "Student.h"
#include "Semester.h"
struct Course {
    std::string ID, classID;
    std::string name, teacher;

    int credits, maxEnroll;
    Weekday weekday;
    Session session;

    Semester* ptrSemester;
    Vector<Scoreboard*> scoreboards;

    Course(const std::string& ID = defaultStr, const std::string& classID = defaultStr, const std::string& name = defaultStr, const std::string& teacher = defaultStr, const int& credits = 0, const int& maxEnroll = 50, Semester* ptrSemester = nullptr, Vector<Scoreboard*> scoreboards = Vector<Scoreboard*>());

    Student* getStudent(const std::string& studentID);

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