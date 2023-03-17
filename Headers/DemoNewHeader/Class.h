#ifndef CLASS_H
#define CLASS_H

#include "Components.h"
#include "Student.h"
struct Class {
    std::string name;
    Vector<Student> students;

    void addStudent(const Student& student) {
        students.append(student);
        (students.end() - 1)->myClass = this;
    }

    void removeStudent(const Student& student) {
        Student* pos = students.find(student);
        pos->myClass = nullptr;
        students.remove(pos);
    }
};
#endif // !CLASS_H

