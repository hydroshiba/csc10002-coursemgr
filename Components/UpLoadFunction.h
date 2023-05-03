#ifndef UPLOAD_FUNCTION_H
#define UPLOAD_FUNCTION_H

#include "Components.h"
#include "User.h"

bool uploadAllData(Vector<Staff>& staffs, Vector<Student> &students, Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

bool uploadListStaff(Vector<Staff>& staffs);

bool uploadListStudent(Vector<Student>& students);

bool uploadListSchoolYearFolder(Vector<Student> &students, Vector <SchoolYear>& schoolYears);

bool uploadSchoolYearFolder(Vector<Student> &students, SchoolYear& schoolYear);

bool uploadStudentFolder(Class& actClass, Student& student, std::string id);

bool get_students_priority(Vector<Student> &students, Class& actClass);

// AcademicYear

bool uploadListAcademicYearFolder(Vector<Student>& students, Vector<AcademicYear>& academicYears);

bool uploadAcademicYearFolder(Vector<Student>& students, AcademicYear& academicYear);

bool uploadSemesterFolder(Vector<Student>& students, Semester& semester);

bool uploadScoreboardFile(Vector<Student>& students, Course& course);

#endif // !UPLOAD_FUNCTION_H



