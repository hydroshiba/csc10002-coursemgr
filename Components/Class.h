#ifndef CLASS_H
#define CLASS_H

#include "Components.h"
#include "Student.h"
#include "SchoolYear.h"

struct Class {
    SchoolYear* ptrSchoolYear;
    std::string name;
    Vector<Student*> students;
    
    Class(SchoolYear* ptrSchoolYear = nullptr, const std::string& name = defaultStr, const Vector<Student*>& students = Vector<Student*>());

    void set(SchoolYear* ptrSchoolYear, const std::string& name, const Vector<Student*>& students);

    void update(SchoolYear* ptrSchoolYear);

    void update(const std::string& name);

    void update(Vector<Student>& students);

    void addStudent(Student& student);

    void removeStudent(Student& student);

    Vector<std::string> getListCourse();

    Student* getStudent(const std::string& studentID);

    void displayScoreboardScreen(const Semester& semester);

    void displayScoreboardFile(const Semester& semester, std::ofstream& ofs);

};

bool operator==(const Class& classA, const Class& classB);

#endif // !CLASS_H