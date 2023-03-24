#ifndef STUDENT_H
#define STUDENT_H

#include "Components.h"

#include "Date.h"
#include "Scoreboard.h"
#include "User.h"

struct Student : User {
    int number;
    Gender gender;
    Date birth;
    std::string socialID;

    Class* myClass = nullptr;
    Vector<Scoreboard*> scoreboards;

    Scoreboard* getScoreboard(Course& course) {
        Scoreboard* cur = nullptr;

        for (int i = 0; i < scoreboards.size(); ++i)
            if (scoreboards[i]->ptrCourse == &course) {
                cur = scoreboards[i];
                break;
            }
        return cur;
    }
};

bool operator==(const Student &studentA, const Student &studentB) {
    if(studentA.ID != studentB.ID) return false;
    if(studentA.name != studentB.name) return false;
    if(studentA.socialID != studentB.socialID) return false;

    return true;
}

#endif // !STUDENT_H