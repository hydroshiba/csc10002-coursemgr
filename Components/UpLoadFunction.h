#ifndef UPLOAD_FUNCTION_H
#define UPLOAD_FUNCTION_H

#include "Components.h"
#include "User.h"

bool uploadAllData();

bool uploadListStaff();

bool uploadListStudent();

bool uploadListSchoolYearFolder();

bool uploadSchoolYears(SchoolYear& schoolYear);

bool uploadStudentFolder(Class& actClass, Student& student, std::string id);

bool uploadClasses(Class& actClass);

// AcademicYear

bool uploadListAcademicYearFolder();

bool uploadAcademicYears(AcademicYear& academicYear);

bool uploadSemesters(Semester& semester);

bool uploadCourses(Course& course);

#endif // !UPLOAD_FUNCTION_H



