#include "SchoolYear.h"

unsigned int SchoolYear::get() {
    return start;
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