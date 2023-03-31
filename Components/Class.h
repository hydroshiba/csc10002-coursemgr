#ifndef CLASS_H
#define CLASS_H

#include "Components.h"
#include "Student.h"

struct Class {
    std::string name;
    Vector<Student> students;

    void addStudent(const Student& student);

    void removeStudent(const Student& student);

    Vector<std::string> getListCourse();

    void viewScoreboardScreen(const Semester& semester);

    void viewScoreboardFile(const Semester& semester, std::ofstream& ofs);
};

bool operator==(const Class& classA, const Class& classB);

#endif // !CLASS_H