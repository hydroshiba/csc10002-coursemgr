#include "SchoolYear.h"

unsigned int SchoolYear::getStartYear() {
    return start;
}

SchoolYear::SchoolYear(const int& start, const Vector<Class>& classes) {
    this->start = start;
    this->classes = classes;
}

void SchoolYear::set(const unsigned int& start, const Vector<Class>& classes) {
    this->start = start;
    this->classes = classes;
}

void SchoolYear::update(const unsigned int& start) {
    this->start = start;
}

void SchoolYear::update(Vector<Class>& classes) {
    this->classes = classes;
}

Student* SchoolYear::getStudent(const std::string& studentID) {
    Student* ptrStudent = nullptr;
    for (int i = 0; i < classes.size(); i++)
    {
        Student* temp = classes[i].getStudent(studentID);
        if (temp != nullptr)
        {
            ptrStudent = temp;
            break;
        }
    }
    return ptrStudent;
}

Class* SchoolYear::getClass(const std::string& className) {
    Class* ptrClass = nullptr;
    for (int i = 0; i < classes.size(); i++)
        if (classes[i].name == className)
        {
            ptrClass = &classes[i];
            break;
        }
    return ptrClass;
}

void SchoolYear::addClass(Class& CLASS) {
    classes.append(CLASS);
    CLASS.ptrSchoolYear = this;
}

void SchoolYear::removeClass(Class& CLASS) {
    classes.remove(CLASS);
    CLASS.ptrSchoolYear = nullptr;
}

std::string SchoolYear::getPeriod() {
    return std::to_string(start) + " - " + std::to_string(start + 4);
}

bool operator==(const SchoolYear& yearA, const SchoolYear& yearB) {
    if (yearA.start != yearB.start) return false;
    return true;
}