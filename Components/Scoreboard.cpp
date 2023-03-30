#include "Scoreboard.h"

Scoreboard::Scoreboard(Course* ptrC, Student* ptrS, const float& midterm, const float& final, const float& other, const float& total) {
    this->midterm = midterm;
    this->final = final;
    this->other = other;
    this->total = total;
    this->ptrCourse = ptrC;
    this->ptrStudent = ptrS;
}

void Scoreboard::setScore(const float& midterm, const float& final, const float& other, const float& total) {
    this->midterm = midterm;
    this->final = final;
    this->other = other;
    this->total = total;
}

bool operator==(const Scoreboard& boardA, const Scoreboard& boardB) {
    if (boardA.ptrCourse != boardB.ptrCourse) return false;
    if (boardA.ptrStudent != boardB.ptrStudent) return false;
    return true;
}