#ifndef UPLOAD_FUNCTION_H
#define UPLOAD_FUNCTION_H

#include "Components.h"
#include "User.h"

void uploadAllData(Vector<Staff::User>& staffs, Vector<Student> &students, Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

void uploadListStaff(Vector<Staff::User>& staffs);

void uploadListStudent(Vector<Student>& students);

void uploadListSchoolYearFolder(Vector<Student> &students, Vector <SchoolYear>& schoolYears);

void uploadSchoolYearFolder(Vector<Student> &students, SchoolYear& schoolYear);

void uploadStudentFolder(Class& actClass, Student& student, std::string id);

void get_students_priority(Vector<Student> &students, Class& actClass);

// AcademicYear

void uploadListAcademicYearFolder(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

void uploadAcademicYearFolder(Vector<SchoolYear>& schoolYears, AcademicYear& academicYear);

void uploadSemesterFolder(Vector<SchoolYear>& schoolYears, Semester& semester);

void uploadCourseFolder(Course& course);

#endif // !UPLOAD_FUNCTION_H



