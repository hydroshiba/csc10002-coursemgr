#ifndef COURSE_H
#define COURSE_H

#include "Components.h"
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
};

#endif // !COURSE_H

