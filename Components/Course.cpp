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

void Course::displayInfo(std::ostream& outDev) {
    if (&outDev == &std::cout)
        displayInfoScreen();
    else
        displayInfoFile(outDev);
}

void Course::displayInfoScreen() {
    std::cout << "+ Semester ID: " << ptrSemester->semesterID << std::endl;
    std::cout << "+ Course ID: " << ID << std::endl;
    std::cout << "+ Course name: " << name << std::endl;
    std::cout << "+ Class ID: " << classID << std::endl;
    std::cout << "+ Teacher: " << teacher << std::endl;
    std::cout << "+ Number of credits: " << credits << std::endl;
    std::cout << "+ Weekday: " << weekday << std::endl;
    std::cout << "+ Session: " << session << std::endl;
}

void Course::displayInfoFile(std::ostream& ofs) {
    ofs << "Semester ID," << ptrSemester->semesterID << std::endl;
    ofs << "Course ID," << ID << std::endl;
    ofs << "Course name," << name << std::endl;
    ofs << "Class ID," << classID << std::endl;
    ofs << "Teacher," << teacher << std::endl;
    ofs << "Number of credits," << credits << std::endl;
    ofs << "Weekday," << weekday << std::endl;
    ofs << "Session," << session << std::endl;
}

void Course::importScoreBoards(std::ifstream& ifs) {
    const char delimiter = ',';
    const int nSkipLine = 8;
    const int nSkipInfo = 3;
    std::string s = "";
    for (int i = 0; i < nSkipLine; i++)
        std::getline(ifs, s);
    int No = 0;
    while (!ifs.eof())
    {
        float midterm, final, other, total;
        for (int i = 0; i < nSkipInfo; i++)
            std::getline(ifs, s, delimiter);
        std::getline(ifs, s, delimiter);
        midterm = std::stof(s);
        std::getline(ifs, s, delimiter);
        final = std::stof(s);
        std::getline(ifs, s, delimiter);
        other = std::stof(s);
        std::getline(ifs, s, delimiter);
        total = std::stof(s);
        scoreboards[No]->setScore(midterm, final, other, total);
    }
}

void Course::displayScoreBoards(std::ostream& outDev) {
    if (&outDev == &std::cout)
        displayScoreBoardScreen();
    else
        displayScoreBoardFile(outDev);
}

void Course::displayScoreBoardFile(std::ostream& outDev) {
    displayInfoFile(outDev);
    outDev << "No," << "ID," << "Fullname," << "Midterm," << "Final," << "Other," << "Total";
    outDev << std::endl;
    for (int i = 0; i < scoreboards.size(); i++)
    {
        outDev << i + 1 << "," << scoreboards[i]->ptrStudent->ID << "," << scoreboards[i]->ptrStudent->name.get() << ",";
        outDev << scoreboards[i]->midterm << "," << scoreboards[i]->final << "," << scoreboards[i]->other << ",";
        outDev << scoreboards[i]->total << std::endl;
    }
}

void Course::displayScoreBoardScreen() {
    displayInfoScreen();
    const int noMaxLength = 3;
    const int idMaxLength = 10;
    const int fullNameMaxLength = 20;
    const int midtermMaxLength = 10;
    const int finalMaxLength = 8;
    const int totalMaxLength = 8;
    const int otherMaxLength = 8;
    std::cout << std::setw(noMaxLength) << std::left << "No";
    std::cout << std::setw(idMaxLength) << std::left << "ID";
    std::cout << std::setw(fullNameMaxLength) << std::left << "Fullname";
    std::cout << std::setw(midtermMaxLength) << std::left << "Midterm";
    std::cout << std::setw(finalMaxLength) << std::left << "Final";
    std::cout << std::setw(otherMaxLength) << std::left << "Other";
    std::cout << std::setw(totalMaxLength) << std::left << "Total";
    std::cout << std::endl;
    for (int i = 0; i < scoreboards.size(); i++)
    {
        std::cout << std::setw(noMaxLength) << std::left << i + 1;
        std::cout << std::setw(idMaxLength) << std::left << scoreboards[i]->ptrStudent->ID;
        std::cout << std::setw(fullNameMaxLength) << std::left << scoreboards[i]->ptrStudent->name.get();
        std::cout << std::setw(midtermMaxLength) << std::left << scoreboards[i]->midterm;
        std::cout << std::setw(finalMaxLength) << std::left << scoreboards[i]->final;
        std::cout << std::setw(otherMaxLength) << std::left << scoreboards[i]->other;
        std::cout << std::setw(totalMaxLength) << std::left << scoreboards[i]->total;
        std::cout << std::endl;
    }
}



bool operator==(const Course& courseA, const Course& courseB) {
    if (courseA.ID != courseB.ID) return false;
    if (courseA.classID != courseB.classID) return false;
    return true;
}