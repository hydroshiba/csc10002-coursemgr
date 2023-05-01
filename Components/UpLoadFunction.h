#ifndef UPLOAD_FUNCTION_H
#define UPLOAD_FUNCTION_H

#include "Components.h"
#include "User.h"

void uploadAllData(Vector<Staff>& staffs, Vector<Student> &students, Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

void uploadListStaff(Vector<Staff>& staffs);

void uploadListStudent(Vector<Student>& students);

void uploadListSchoolYearFolder(Vector<Student> &students, Vector <SchoolYear>& schoolYears);

void uploadSchoolYearFolder(Vector<Student> &students, SchoolYear& schoolYear);

void uploadStudentFolder(Class& actClass, Student& student, std::string id);

void get_students_priority(Vector<Student> &students, Class& actClass);

// AcademicYear

void uploadListAcademicYearFolder(Vector<Student>& students, Vector<AcademicYear>& academicYears);

void uploadAcademicYearFolder(Vector<Student>& students, AcademicYear& academicYear);

void uploadSemesterFolder(Vector<Student>& students, Semester& semester);

void uploadScoreboardFile(Vector<Student>& students, Course& course);

#endif // !UPLOAD_FUNCTION_H



