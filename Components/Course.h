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

    Vector<Scoreboard*> scoreboards;

    void addStudent(Student& student) {
        Scoreboard* newBoard = new Scoreboard(this, &student);
        student.scoreboards.append(newBoard);
        scoreboards.append(newBoard);
    }

    void removeStudent(Student& student) {
        Scoreboard* cur = nullptr;

        for (int i = 0; i < scoreboards.size(); ++i)
            if (scoreboards[i]->ptrStudent == &student) {
                cur = scoreboards[i];
                break;
            }

        if (cur) {
            student.scoreboards.remove(cur);
            scoreboards.remove(cur);
            delete cur;
        }
    }

    Scoreboard* getScoreboard(Student& student) {
        Scoreboard* cur = nullptr;

        for (int i = 0; i < scoreboards.size(); ++i)
            if (scoreboards[i]->ptrStudent == &student) {
                cur = scoreboards[i];
                break;
            }

        return cur;
    }
    
    void display(std::ostream& outDev = std::cout) {
        outDev << "+ Course ID: " << ID << std::endl;
        outDev << "+ Course name: " << name << std::endl;
        outDev << "+ Class ID: " <<  classID << std::endl;
        outDev << "+ Teacher: " << teacher << std::endl;
        outDev << "+ Number of credits: " << credits << std::endl;
        outDev << "+ Weekday: " << weekday << std::endl;
        outDev << "+ Session: " << session << std::endl;
    }
};

bool operator==(const Course &courseA, const Course &courseB) {
    if(courseA.ID != courseB.ID) return false;
    if(courseA.classID != courseB.classID) return false;
    return true;
}

#endif // !COURSE_H