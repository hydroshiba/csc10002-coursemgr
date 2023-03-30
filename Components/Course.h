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
    
    void display(std::ostream& outDev);

    void displayScreen();

    void displayCSVFile(std::ostream& ofs);

    void importScoreBoards(std::ifstream& ifs) {
        const char delimiter = ',';
        const int nSkipLine = 8;
        const int nSkipInfo = 3;
        std::string s = "";
        for (int i = 0; i < nSkipLine; i++)
            std::getline(ifs, s); 
        int No = 0;
        while (!ifs.eof())
        {
            float midterm, final, other, total;
            for (int i = 0; i < nSkipInfo; i++)
                std::getline(ifs, s, delimiter);
            std::getline(ifs, s, delimiter);
            midterm = std::stof(s);
            std::getline(ifs, s, delimiter);
            final = std::stof(s);
            std::getline(ifs, s, delimiter);
            other = std::stof(s);
            std::getline(ifs, s, delimiter);
            total = std::stof(s);
            scoreboards[No]->setScore(midterm, final, other, total);
        }
    }
};

bool operator==(const Course& courseA, const Course& courseB);

#endif // !COURSE_H