#ifndef UPLOAD_FUNCTION_H
#define UPLOAD_FUNCTION_H

#include "Components.h"
#include "User.h"

bool uploadAllData();

bool uploadListStaff();

bool uploadListStudent();

bool uploadListSchoolYear();

bool uploadSchoolYear(SchoolYear& schoolYear);

bool uploadStudent(Class& actClass, Student& student, std::string id);

bool uploadClass(Class& actClass);

// AcademicYear

bool uploadListAcademicYear();

bool uploadAcademicYear(AcademicYear& academicYear);

bool uploadSemester(Semester& semester);

bool uploadCourse(Course& course);

#endif // !UPLOAD_FUNCTION_H



