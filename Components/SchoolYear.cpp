#include "SchoolYear.h"

unsigned int SchoolYear::get() {
    return start;
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

void SchoolYear::addClass(const Class& newClass) {
    classes.append(newClass);
}

void SchoolYear::removeClass(const Class& newClass) {
    classes.remove(newClass);
}

std::string SchoolYear::getPeriod() {
    return std::to_string(start) + " - " + std::to_string(start + 4);
}

bool operator==(const SchoolYear& yearA, const SchoolYear& yearB) {
    if (yearA.start != yearB.start) return false;
    return true;
}