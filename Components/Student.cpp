#include "Student.h"

Student::Student(const Name& name, const std::string& id, const std::string& password, const Gender& gender, const Date& birth, const std::string& socialID, Class* ptrClass, const Vector<Scoreboard*>& scoreboards) : User(name, id, password) {
    this->ID = id;
    this->gender = gender;
    this->birth = birth;
    this->socialID = socialID;
    this->ptrClass = ptrClass;
    this->scoreboards = scoreboards;
    setPassword(password);
}

void Student::set(const Name& name, const std::string& id, const std::string& password, const Gender& gender, const Date& birth, const std::string& socialID, Class* ptrClass, const Vector<Scoreboard*>& scoreboards) {
    this->name = name;
    this->ID = id;
    this->gender = gender;
    this->birth = birth;
    this->socialID = socialID;
    this->ptrClass = ptrClass;
    this->scoreboards = scoreboards;
    setPassword(password);
}

void Student::setName(const Name& name) {
    this->name = name;
}

void Student::setGender(const Gender& gender) {
    this->gender = gender;  
}

void Student::setBirth(const Date& birth) {
    this->birth = birth;  
}

void Student::setSocialID(const std::string& socialID) {
    this->socialID = socialID; 
}

void Student::setClass(Class* ptrClass) {
    this->ptrClass = ptrClass;
}

void Student::setScoreboards(Vector<Scoreboard*>& scoreboards) {
    this->scoreboards = scoreboards;
}

Vector<Scoreboard*> Student::getScoreboards(const Semester& semester) const{
    Vector<Scoreboard*> scoreboards;
    for (int i = 0; i < this->scoreboards.size(); i++) {
        if (this->scoreboards[i]->ptrCourse->ptrSemester == &semester)
            scoreboards.append(this->scoreboards[i]);
    }
    return scoreboards;
}

Scoreboard* Student::getScoreboard(const string& courseID) const {
    Scoreboard* ptrScoreboard = nullptr;
    for (int i = 0; i < scoreboards.size(); i++) {
        if (scoreboards[i]->ptrCourse->ID == courseID) {
            ptrScoreboard = scoreboards[i];
            break;
        }
    }
    return ptrScoreboard;
}


Scoreboard* Student::getScoreboard(Course& course) const {
    Scoreboard* cur = nullptr;

    for (int i = 0; i < scoreboards.size(); ++i)
        if (scoreboards[i]->ptrCourse == &course) {
            cur = scoreboards[i];
            break;
        }
    return cur;
}

float Student::getGPA() const {
    int nCredits = 0;
    float totalMark = 0;
    size_t n = scoreboards.size();
    for (int i = 0; i < n; i++)
    {
        totalMark = totalMark + scoreboards[i]->total;
        nCredits = nCredits + scoreboards[i]->ptrCourse->credits;
    }
    return totalMark * 1.0 / n;
}

float Student::getGPA(const Semester& semester) const{
    int nCredits = 0;
    float totalMark = 0;
    int n = 0;
    for (int i = 0; i < scoreboards.size(); i++)
        if (scoreboards[i]->ptrCourse->ptrSemester == &semester)
        {
            totalMark = totalMark + scoreboards[i]->total;
            nCredits = nCredits + scoreboards[i]->ptrCourse->credits;
            n++;
        }
    return totalMark * 1.0 / n;
} // 

void Student::setInfoToClass(std::ifstream &ifs){
    std::string id, first_name, last_name, gender, sID, day, month, year, sTemp;
    getline(ifs, sTemp, ',');
    getline(ifs, id, ',');
    getline(ifs, first_name, ',');
    getline(ifs, last_name, ',');
    getline(ifs, gender, ',');
    getline(ifs, day, '/');
    getline(ifs, month, '/');
    getline(ifs, year, ',');
    getline(ifs, sID);

    ID = id;
    Name name(first_name, last_name);
    setName(name);
    gender = (gender == "Male") ? male : female;
    birth.set(stoi(day), stoi(month), stoi(year));
    socialID = sID;
}

void Student::setInfoToCourseCSV(std::ifstream &ifs){
    std::string id, first, last, sTemp;
    getline(ifs, sTemp, ',');
    getline(ifs, id, ',');
    getline(ifs, first, ',');
    getline(ifs, last);

    ID = id;
    Name name(first, last);
    setName(name);
}

void Student::setInfoCourseConsole(std::string &actClass){
    std::string first, last;
    std::cout << "Enter id: "; std::cin >> ID;
    std::cout << "Enter first name: "; std::cin >> first;
    std::cout << "Enter last name: "; std::cin >> last;
    Name name(first, last);
    setName(name);
    std::cout << "Enter student's class: "; std::cin >> actClass;
}


bool operator==(const Student& studentA, const Student& studentB) {
    if (studentA.ID != studentB.ID) return false;
    if (studentA.name != studentB.name) return false;
    if (studentA.socialID != studentB.socialID) return false;

    return true;
}