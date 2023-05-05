#ifndef DISPLAY_FUNCTION_H
#define DISPLAY_FUNCTION_H

#include <iostream>
#include <fstream>

#include "Components.h"

/*		Display function	*/

// DropBox
Vector<string> getListSchoolYear(Vector<SchoolYear>& schoolYears);

Vector<string> getListAcademicYear(Vector<AcademicYear>& academicYears);

Vector<string> getListClass(const SchoolYear& schoolYear);

Vector<string> getListSemester(const AcademicYear& academicYear);

Vector<string> getListCourse(const Semester& semester);

// Table
Vector<Vector<string>> getTableContentOfListSchoolYear();

Vector<Vector<string>> getTableContentOfListClass(const SchoolYear& schoolYear);

Vector<Vector<string>> getTableContentOfListStudentInClass(const Class& CLASS);

Vector<Vector<string>> getTableContentOfListScoreboardInSemesterInClass(const Class& CLASS, const Semester& semester);

Vector<Vector<string>> getTableContentOfListScoreboardInClass(const Class& CLASS);

Vector<Vector<string>> getTableContentOfScoreboardOfStudent(const Student& student);

Vector<Vector<string>> getTableContentOfListAcademicYear();

Vector<Vector<string>> getTableContentOfListSemester(const AcademicYear& academicYear);

Vector<Vector<string>> getTableContentOfListCourse(const Semester& semester);

Vector<Vector<string>> getTableContentOfListStudentInCourse(const Course& course); // Student and scoreboards

// 

bool removeTable(Vector<Vector<string>>& table);

#endif // !DISPLAY_FUNCTION_H
