#ifndef SCHOOL_YEAR_H
#define SCHOOL_YEAR_H

#include "Components.h"

struct SchoolYear {
    unsigned int start;
    Vector<Class> classes;

    unsigned int get() {
        return start;
    }

    void addClass(const Class& newClass) {
        classes.append(newClass);
    }

    void removeClass(const Class& newClass) {
        classes.remove(newClass);
    }

    std::string getPeriod() {
        return std::to_string(start) + " - " + std::to_string(start + 4);
    }
};

#endif 

