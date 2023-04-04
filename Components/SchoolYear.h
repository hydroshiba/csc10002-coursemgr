#ifndef SCHOOL_YEAR_H
#define SCHOOL_YEAR_H

#include "Components.h"
#include "Class.h"

struct SchoolYear {
    unsigned int start;
    Vector<Class> classes;

    unsigned int get();

    Class* getClass(const std::string& className) {
        Class* ptrClass = nullptr;
        for (int i = 0; i < classes.size(); i++)
            if (classes[i].name == className)
            {
                ptrClass = &classes[i];
                break;
            }
        return ptrClass;
    }

    void addClass(const Class& newClass);

    void removeClass(const Class& newClass);

    std::string getPeriod();
};

bool operator==(const SchoolYear& yearA, const SchoolYear& yearB);

#endif