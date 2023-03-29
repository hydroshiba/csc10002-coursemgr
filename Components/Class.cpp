#include "Class.h"

void Class::addStudent(const Student& student){}

void Class::removeStudent(const Student& student){}

bool operator==(const Class& classA, const Class& classB) {
    if (classA.name != classB.name) return false;
    return true;
}