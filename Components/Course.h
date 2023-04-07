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

    Course(const std::string& ID = defaultStr, const std::string& classID = defaultStr, const std::string& name = defaultStr, const std::string& teacher = defaultStr, const int& credits = 0, const int& maxEnroll = 50, const Weekday& weekday = MON, const Session& session = S1, Semester* ptrSemester = nullptr, const Vector<Scoreboard*>& scoreboards = Vector<Scoreboard*>());

    void set(const std::string& ID, const std::string& classID, const std::string& name, const std::string& teacher, const int& credits, const int& maxEnroll, const Weekday& weekday, const Session& session, Semester* ptrSemester, const Vector<Scoreboard*>& scoreboards);
    
    void updateID(const std::string& ID);
    void updateClassID(const std::string& classID);
    void updateName(const std::string& name);
    void updateTeacher(const std::string& teacher);
    void updateCredits(const int& credits);
    void updateMaxEnroll(const int& maxEnroll);
    void updateWeekday(const Weekday& weekday);
    void updateSession(const Session& session);
    void updateSemester(Semester* ptrSemester);
    void updateScoreboard(Vector<Scoreboard*> scoreboards);

    Student* getStudent(const std::string& studentID);

    Scoreboard* getScoreboard(const std::string& studentID);

    void addStudent(Student& student);  

    void removeStudent(Student& student);
    
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