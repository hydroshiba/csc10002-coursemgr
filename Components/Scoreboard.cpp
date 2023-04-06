#include "Scoreboard.h"

Scoreboard::Scoreboard(Course* ptrCourse, Student* ptrStudent, const float& midterm, const float& final, const float& other, const float& total) {
    this->midterm = midterm;
    this->final = final;
    this->other = other;
    this->total = total;
    this->ptrCourse = ptrCourse;
    this->ptrStudent = ptrStudent;
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