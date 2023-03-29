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

void Student::setInfoToClass(std::ifstream &ifs){
    std::string no, id, first_name, last_name, gender, sID, day, month, year;
    getline(ifs, no, ',');
    getline(ifs, id, ',');
    getline(ifs, first_name, ',');
    getline(ifs, last_name, ',');
    getline(ifs, gender, ',');
    getline(ifs, day, '/');
    getline(ifs, month, '/');
    getline(ifs, year, ',');
    getline(ifs, sID);

    number = stoi(no);
    ID = id;
    setName(first_name, last_name);
    gender = (gender == "Male") ? male : female;
    birth.set(stoi(day), stoi(month), stoi(year));
    socialID = sID;
}

void Student::setInfoToCourseCSV(std::ifstream &ifs, std::string &actClass){
    std::string no, id, first, last;
    getline(ifs, no, ',');
    getline(ifs, id, ',');
    getline(ifs, first, ',');
    getline(ifs, last, ',');
    getline(ifs, actClass);

    number = stoi(no);
    ID = id;
    setName(first, last);
}

void Student::setInfoCourseConsole(std::string &actClass){
    std::string first, last;
    std::cout << "Enter number: "; std::cin >> number;
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