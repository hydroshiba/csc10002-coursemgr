#ifndef SCHOOL_YEAR_H
#define SCHOOL_YEAR_H

#include "Components.h"
#include "Class.h"

struct SchoolYear {
    unsigned int start;
    Vector<Class> classes;

    unsigned int getStartYear();

    SchoolYear(const int& start = 0, const Vector<Class>& classes = Vector<Class>());

    void set(const unsigned int& start, const Vector<Class>& classes);

    void update(const unsigned int& start);

    void update(Vector<Class>& classes);

    Student* getStudent(const std::string& studentID);

    Class* getClass(const std::string& className);

    void addClass(Class& CLASS);

    void removeClass(Class& CLASS);

    void removeAllClass();

    std::string getPeriod();
};

bool operator==(const SchoolYear& yearA, const SchoolYear& yearB);

#endif