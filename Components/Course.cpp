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


void Course::displayInfoTable(Vector<Vector<string>>& table) const{
    table.resize(9);
    for (int i = 0; i<9; ++i)
        table[i].resize(2);
    table[0][0] = "Course ID"; table[0][1] = this->ID;
    table[1][0] = "Class ID"; table[1][1] = this->classID;
    table[2][0] = "Course name"; table[2][1] = this->name;
    table[3][0] = "Teacher"; table[3][1] = teacher;
    table[4][0] = "Number of credits"; table[4][1] = std::to_string(credits);
    table[5][0] = "Max enroll"; table[5][1] = std::to_string(maxEnroll);
    table[6][0] = "Weekday"; table[6][1] = weekday_to_string(weekday);
    table[7][0] = "Session"; table[7][1] = session_to_string(session);
    table[8][0] = "Number of students"; table[8][1] = std::to_string(scoreboards.size());
}

void Course::displayInfoFile(std::ostream& ofs) {
    ofs << "Course ID," << ID << std::endl;
    ofs << "Class ID," << classID << std::endl;
    ofs << "Course name," << name << std::endl;
    ofs << "Teacher," << teacher << std::endl;
    ofs << "Number of credits," << credits << std::endl;
    ofs << "Weekday," << weekday << std::endl;
    ofs << "Session," << session << std::endl;
    ofs << "Number of students," << scoreboards.size() << std::endl;
}

void Course::importScoreBoards(std::ifstream& ifs) {
    const char delimiter = ',';
    const int nSkipLine = 9;
    const int nSkipInfo = 2;
    std::string s = "";
    for (int i = 0; i < nSkipLine; i++)
        std::getline(ifs, s);
    int No = 0;
    getline(ifs, s);
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
        std::getline(ifs, s);
        total = std::stof(s);
        scoreboards[No]->setScore(midterm, final, other, total);
        No++;
    }
}

void Course::removeAllStudent() {
    if (scoreboards.size() == 0)
        return;
    for (int i = 0; i < scoreboards.size(); i++) {
        scoreboards[i]->ptrStudent->scoreboards.remove(&scoreboards[i]);
        delete scoreboards[i];
    }
    scoreboards.resize(0);
}

bool operator==(const Course& courseA, const Course& courseB) {
    if (courseA.ID != courseB.ID) return false;
    if (courseA.classID != courseB.classID) return false;
    return true;
}