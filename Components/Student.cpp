#include "Student.h"

Scoreboard* Student::getScoreboard(Course& course) {
    Scoreboard* cur = nullptr;

    for (int i = 0; i < scoreboards.size(); ++i)
        if (scoreboards[i]->ptrCourse == &course) {
            cur = scoreboards[i];
            break;
        }
    return cur;
}

float Student::getGPA() {
    int nCredits = 0;
    float totalMark = 0;
    for (int i = 0; i < scoreboards.size(); i++)
    {
        totalMark = totalMark + scoreboards[i]->total;
        nCredits = nCredits + scoreboards[i]->ptrCourse->credits;
    }
    return totalMark;
}

bool operator==(const Student& studentA, const Student& studentB) {
    if (studentA.ID != studentB.ID) return false;
    if (studentA.name != studentB.name) return false;
    if (studentA.socialID != studentB.socialID) return false;

    return true;
}