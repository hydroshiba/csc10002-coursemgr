#include "Course.h"

void Course::addStudent(Student& student) {
    Scoreboard* newBoard = new Scoreboard(this, &student);
    student.scoreboards.append(newBoard);
    scoreboards.append(newBoard);
}

void Course::removeStudent(Student& student) {
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

Scoreboard* Course::getScoreboard(Student& student) {
    Scoreboard* cur = nullptr;

    for (int i = 0; i < scoreboards.size(); ++i)
        if (scoreboards[i]->ptrStudent == &student) {
            cur = scoreboards[i];
            break;
        }

    return cur;
}

void Course::display(std::ostream& outDev) {
    if (&outDev == &std::cout)
        displayScreen();
    else
        displayCSVFile(outDev);
}

void Course::displayScreen() {
    std::cout << "+ Semester ID: " << ptrSemester->semesterID << std::endl;
    std::cout << "+ Course ID: " << ID << std::endl;
    std::cout << "+ Course name: " << name << std::endl;
    std::cout << "+ Class ID: " << classID << std::endl;
    std::cout << "+ Teacher: " << teacher << std::endl;
    std::cout << "+ Number of credits: " << credits << std::endl;
    std::cout << "+ Weekday: " << weekday << std::endl;
    std::cout << "+ Session: " << session << std::endl;
}

void Course::displayCSVFile(std::ostream& ofs) {
    ofs << "Semester ID," << ptrSemester->semesterID << std::endl;
    ofs << "Course ID," << ID << std::endl;
    ofs << "Course name," << name << std::endl;
    ofs << "Class ID," << classID << std::endl;
    ofs << "Teacher," << teacher << std::endl;
    ofs << "Number of credits," << credits << std::endl;
    ofs << "Weekday," << weekday << std::endl;
    ofs << "Session," << session << std::endl;
}

bool operator==(const Course& courseA, const Course& courseB) {
    if (courseA.ID != courseB.ID) return false;
    if (courseA.classID != courseB.classID) return false;
    return true;
}