#ifndef SCHOOL_YEAR_H
#define SCHOOL_YEAR_H

#include "Components.h"
#include "Class.h"

struct SchoolYear {
    unsigned int start;
    Vector<Class> classes;

    unsigned int getStartYear();

    SchoolYear(const int& start = 0, Vector<Class> classes = Vector<Class>());

    Class* getClass(const std::string& className);

    void addClass(Class& CLASS);

    void removeClass(Class& CLASS);

    std::string getPeriod();
};

bool operator==(const SchoolYear& yearA, const SchoolYear& yearB);

#endif