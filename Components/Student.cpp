#include "Student.h"

Student::Student(const Name& name, const std::string& id, const uint64_t password, const Gender& gender, const Date& birth, const std::string& socialID, Class* ptrClass, Vector<Scoreboard*>& scoreboards) : User(name, id, password) {
    this->ID = id;
    this->gender = gender;
    this->birth = birth;
    this->socialID = socialID;
    this->ptrClass = ptrClass;
    this->scoreboards = scoreboards;
}

void Student::set(const Name& name, const std::string& id, const uint64_t password, const Gender& gender, const Date& birth, const std::string& socialID, Class* ptrClass, Vector<Scoreboard*>& scoreboards) {
    this->name = name;
    this->ID = id;
    this->gender = gender;
    this->birth = birth;
    this->socialID = socialID;
    this->ptrClass = ptrClass;
    this->scoreboards = scoreboards;
}

void Student::update(const Name& name) {
    this->name = name;
}

void Student::update(const Gender& gender) {
    this->gender = gender;  
}

void Student::update(const Date& birth) {
    this->birth = birth;  
}

void Student::update(const std::string& socialID) {
    this->socialID = socialID; 
}

void Student::update(Class* ptrClass) {
    this->ptrClass = ptrClass;
}

void Student::update(Vector<Scoreboard*>& scoreboards) {
    this->scoreboards = scoreboards;
}

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

float Student::getGPA(const Semester& semester) {
    int nCredits = 0;
    float totalMark = 0;
    for (int i = 0; i < scoreboards.size(); i++)
        if (scoreboards[i]->ptrCourse->ptrSemester == &semester)
        {
            totalMark = totalMark + scoreboards[i]->total;
            nCredits = nCredits + scoreboards[i]->ptrCourse->credits;
        }
    return totalMark;
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
    setName(first_name, last_name);
    gender = (gender == "Male") ? male : female;
    birth.set(stoi(day), stoi(month), stoi(year));
    socialID = sID;
}

void Student::setInfoToCourseCSV(std::ifstream &ifs, std::string &actClass){
    std::string id, first, last, sTemp;
    getline(ifs, sTemp, ',');
    getline(ifs, id, ',');
    getline(ifs, first, ',');
    getline(ifs, last, ',');
    getline(ifs, actClass);

    ID = id;
    setName(first, last);
}

void Student::setInfoCourseConsole(std::string &actClass){
    std::string first, last;
    std::cout << "Enter id: "; std::cin >> ID;
    std::cout << "Enter first name: "; std::cin >> first;
    std::cout << "Enter last name: "; std::cin >> last;
    setName(first, last);
    std::cout << "Enter student's class: "; std::cin >> actClass;
}

bool operator==(const Student& studentA, const Student& studentB) {
    if (studentA.ID != studentB.ID) return false;
    if (studentA.name != studentB.name) return false;
    if (studentA.socialID != studentB.socialID) return false;

    return true;
}