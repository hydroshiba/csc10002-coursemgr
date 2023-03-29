#ifndef STUDENT_H
#define STUDENT_H

#include "Components.h"

#include "Date.h"
#include "Scoreboard.h"
#include "User.h"
#include "Course.h"

struct Student : User {
    int number;
    Gender gender;
    Date birth;
    std::string socialID;

    Class* myClass = nullptr;
    Vector<Scoreboard*> scoreboards;

    Scoreboard* getScoreboard(Course& course);

    float getGPA();
    
};

bool operator==(const Student& studentA, const Student& studentB);

#endif // !STUDENT_H