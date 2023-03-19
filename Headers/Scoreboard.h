#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include "Components.h"

struct Scoreboard {
    float midterm, final, other, total;
    Course*  ptrCourse;
    Student* ptrStudent;

    Scoreboard(Course* ptrC = nullptr, Student* ptrS = nullptr, float midterm = -1, float final = -1, float other = -1, float total = -1){
        this->midterm = midterm;
        this->final = final;
        this->other = other;
        this->total = total;
        this->ptrCourse = ptrC;
        this->ptrStudent = ptrS;
    }
};

#endif 

