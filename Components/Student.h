#ifndef STUDENT_H
#define STUDENT_H

#include "Components.h"

#include "Date.h"
#include "Scoreboard.h"
#include "User.h"
#include "Course.h"

struct Student : User {
    Gender gender;
    Date birth;
    std::string socialID;

    Class* ptrClass;
    Vector<Scoreboard*> scoreboards;

    Student(const Name& name = { defaultStr, defaultStr }, const std::string & id = defaultStr, const uint64_t password = 0, const Gender & gender = male, const Date & birth = { 0, 0, 0 }, const std::string & socialID = defaultStr, Class * ptrClass = nullptr, Vector<Scoreboard*> scoreboards = Vector<Scoreboard*>());
    
    Scoreboard* getScoreboard(Course& course);

    float getGPA(); // Overall GPA
    float getGPA(const Semester& semester); // Current semester GPA

    void setInfoToClass(std::ifstream &ifs);
    void setInfoToCourseCSV(std::ifstream &ifs, std::string& actClass);
    void setInfoCourseConsole(std::string &actClass);

};

bool operator==(const Student& studentA, const Student& studentB);

#endif // !STUDENT_H