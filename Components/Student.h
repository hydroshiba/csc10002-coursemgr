#ifndef STUDENT_H
#define STUDENT_H

#include "Components.h"

#include "Date.h"
#include "Scoreboard.h"
#include "User.h"
#include "Course.h"

struct Student : public User {
    Gender gender;
    Date birth;
    std::string socialID;

    Class* ptrClass;
    Vector<Scoreboard*> scoreboards;

    Student(const Name& name = { defaultStr, defaultStr }, const std::string& id = defaultStr, const std::string& password = "", const Gender& gender = male, const Date& birth = {0, 0, 0}, const std::string& socialID = defaultStr, Class* ptrClass = nullptr, const Vector<Scoreboard*>& scoreboards = Vector<Scoreboard*>());
    
    Scoreboard* getScoreboard(Course& course);

    void set(const Name& name, const std::string& id, const std::string& password, const Gender& gender, const Date& birth, const std::string& socialID, Class* ptrClass, const Vector<Scoreboard*>& scoreboards);

    void setName(const Name& name);
    void setGender(const Gender& gender);
    void setBirth(const Date& birth);
    void setSocialID(const std::string& socialID);
    void setClass(Class* ptrClass);
    void setScoreboards(Vector<Scoreboard*>& scoreboards);

    float getGPA(); // Overall GPA
    float getGPA(const Semester& semester); // Current semester GPA

    void setInfoToClass(std::ifstream &ifs);
    void setInfoToCourseCSV(std::ifstream &ifs);
    void setInfoCourseConsole(std::string &actClass);

    //Student& operator = (const Student& student);
};

bool operator==(const Student& studentA, const Student& studentB);

#endif // !STUDENT_H