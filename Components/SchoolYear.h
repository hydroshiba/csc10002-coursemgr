#ifndef SCHOOL_YEAR_H
#define SCHOOL_YEAR_H

#include "Components.h"
#include "Class.h"

struct SchoolYear {
    unsigned int start;
    Vector<Class> classes;

    unsigned int get();

    void addClass(const Class& newClass);

    void removeClass(const Class& newClass);

    std::string getPeriod();
};

bool operator==(const SchoolYear& yearA, const SchoolYear& yearB);

#endif