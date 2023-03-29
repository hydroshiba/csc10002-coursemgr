#include "Scoreboard.h"

Scoreboard::Scoreboard(Course* ptrC, Student* ptrS, float midterm, float final, float other, float total) {
    this->midterm = midterm;
    this->final = final;
    this->other = other;
    this->total = total;
    this->ptrCourse = ptrC;
    this->ptrStudent = ptrS;
}

bool operator==(const Scoreboard& boardA, const Scoreboard& boardB) {
    if (boardA.ptrCourse != boardB.ptrCourse) return false;
    if (boardA.ptrStudent != boardB.ptrStudent) return false;
    return true;
}