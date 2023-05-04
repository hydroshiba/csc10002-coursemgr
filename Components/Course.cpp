#include "Course.h"

Course::Course(const std::string& ID, const std::string& classID, const std::string& name, const std::string& teacher, const int& credits, const int& maxEnroll, const Weekday& weekday, const Session& session, Semester* ptrSemester, const Vector<Scoreboard*>& scoreboards) {
    this->ID = ID;
    this->classID = classID;
    this->name = name;
    this->teacher = teacher;
    this->credits = credits;
    this->maxEnroll = maxEnroll;
    this->weekday = weekday;
    this->session = session;
    this->ptrSemester = ptrSemester;
    this->scoreboards = scoreboards;
}

void Course::set(const std::string& ID, const std::string& classID, const std::string& name, const std::string& teacher, const int& credits, const int& maxEnroll, const Weekday& weekday, const Session& session, Semester* ptrSemester, const Vector<Scoreboard*>& scoreboards) {
    this->ID = ID;
    this->classID = classID;
    this->name = name;
    this->teacher = teacher;
    this->credits = credits;
    this->maxEnroll = maxEnroll;
    this->weekday = weekday;
    this->session = session;
    this->ptrSemester = ptrSemester;
    this->scoreboards = scoreboards;
}

void Course::updateID(const std::string& ID) {
    this->ID = ID;
}

void Course::updateClassID(const std::string& classID) {
    this->classID = classID;
}

void Course::updateName(const std::string& name) {
    this->name = name;
}

void Course::updateTeacher(const std::string& teacher) {
    this->teacher = teacher;
}

void Course::updateCredits(const int& credits) {
    this->credits = credits;
}

void Course::updateMaxEnroll(const int& maxEnroll) {
    this->maxEnroll = maxEnroll;
}

void Course::updateWeekday(const Weekday& weekday) {
    this->weekday = weekday;
}

void Course::updateSession(const Session& session) {
    this->session = session;
}

void Course::updateSemester(Semester* ptrSemester) {
    this->ptrSemester = ptrSemester;
}

void Course::updateScoreboard(Vector<Scoreboard*> scoreboards) {
    this->scoreboards = scoreboards;
}

Student* Course::getStudent(const std::string& studentID) {
    Student* ptrStudent = nullptr;
    for (int i = 0; i < scoreboards.size(); i++)
        if (scoreboards[i]->ptrStudent->ID == studentID)
        {
            ptrStudent = scoreboards[i]->ptrStudent;
            break;
        }
    return ptrStudent;
}

void Course::addStudent(Student& student) { 
    Scoreboard* newBoard = new Scoreboard(this, &student);
    student.scoreboards.append(newBoard);
    scoreboards.append(newBoard);
}

void Course::removeStudent(Student& student) {
    Scoreboard* ptrScoreboard = nullptr;

    for (int i = 0; i < scoreboards.size(); ++i)
        if (scoreboards[i]->ptrStudent == &student) {
            ptrScoreboard = scoreboards[i];
            break;
        }

    if (ptrScoreboard != nullptr) {
        student.scoreboards.remove(ptrScoreboard);
        scoreboards.remove(ptrScoreboard);
        ptrScoreboard->ptrCourse = nullptr;
        ptrScoreboard->ptrStudent = nullptr;
        delete ptrScoreboard;
    }
}

Scoreboard* Course::getScoreboard(const std::string& studentID) {
    Scoreboard* ptrScoreboard = nullptr;

    for (int i = 0; i < scoreboards.size(); ++i)
        if (scoreboards[i]->ptrStudent->ID == studentID) {
            ptrScoreboard = scoreboards[i];
            break;
        }
    return ptrScoreboard;
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
    ofs << "Course ID," << ID << std::endl;
    ofs << "Class ID," << classID << std::endl;
    ofs << "Course name," << name << std::endl;
    ofs << "Teacher," << teacher << std::endl;
    ofs << "Number of credits," << credits << std::endl;
    ofs << "Weekday," << weekday << std::endl;
    ofs << "Session," << session << std::endl;
    ofs << "Students," << scoreboards.size() << std::endl;
}

void Course::importScoreBoards(std::ifstream& ifs) {
    const char delimiter = ',';
    const int nSkipLine = 9;
    const int nSkipInfo = 4;
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
    outDev << "No,ID,Midterm,Final,Other,Total" << std::endl;
    for (int i = 0; i < scoreboards.size(); i++)
    {
        outDev << i + 1 << "," << scoreboards[i]->ptrStudent->ID << ",";
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

void Course::removeAllStudent() {
    if (scoreboards.size() == 0)
        return;
    for (int i = 0; i < scoreboards.size(); i++) {
        scoreboards[i]->ptrStudent->scoreboards.remove(&scoreboards[i]);
        delete scoreboards[i];
    }
    scoreboards.resize(0);;
}

bool operator==(const Course& courseA, const Course& courseB) {
    if (courseA.ID != courseB.ID) return false;
    if (courseA.classID != courseB.classID) return false;
    return true;
}