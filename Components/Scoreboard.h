#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Components.h"

struct Scoreboard {
    float midterm, final, other, total;
    Course*  ptrCourse;
    Student* ptrStudent;

    Scoreboard(Course* ptrCourse = nullptr, Student* ptrStudent = nullptr, const float& midterm = -1, const float& final = -1, const float& other = -1, const float& total = -1);

    void setScore(const float& midterm, const float& final, const float& other, const float& total);

    void updateMidterm(const float& midterm);
    void updateFinal(const float& final);
    void updateOther(const float& other);
    void updateTotal(const float& total);
};

bool operator==(const Scoreboard& boardA, const Scoreboard& boardB);

#endif