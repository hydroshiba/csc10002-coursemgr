#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Components.h"

struct Scoreboard {
    float midterm, final, other, total;
    Course*  ptrCourse;
    Student* ptrStudent;

    Scoreboard(Course* ptrC = nullptr, Student* ptrS = nullptr, const float& midterm = -1, const float& final = -1, const float& other = -1, const float& total = -1);

    void setScore(const float& midterm = -1, const float& final = -1, const float& other = -1, const float& total = -1);
};

bool operator==(const Scoreboard& boardA, const Scoreboard& boardB);

#endif