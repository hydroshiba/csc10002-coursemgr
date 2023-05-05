#ifndef DISPLAY_FUNCTION_H
#define DISPLAY_FUNCTION_H

#include <iostream>
#include <fstream>

#include "Components.h"

/*		Display function	*/

// DropBox
Vector<string> getListSchoolYear(Vector<SchoolYear>& schoolYears); // Done

Vector<string> getListAcademicYear(Vector<AcademicYear>& academicYears); // Done

Vector<string> getListClass(const SchoolYear& schoolYear); // Done

Vector<string> getListSemester(const AcademicYear& academicYear); // Done

Vector<string> getListCourse(const Semester& semester); // Done

// Table
Vector<Vector<string>> getTableContentOfListSchoolYear(); // Done

Vector<Vector<string>> getTableContentOfSchoolYear(const SchoolYear& schoolYear); // Done

Vector<Vector<string>> getTableContentOfListStudentInClass(const Class& CLASS); // Done

Vector<Vector<string>> getTableContentOfListScoreboardInSemesterInClass(const Class& CLASS, const string& semesterID);

Vector<Vector<string>> getTableContentOfListScoreboardInClass(const Class& CLASS);

Vector<Vector<string>> getTableContentOfScoreboardOfStudent(const Student& student); // Done

Vector<Vector<string>> getTableContentOfScoreboardInSemesterOfStudent(const Student& student, const string& semesterID);

Vector<Vector<string>> getTableContentOfListAcademicYear(); // Done

Vector<Vector<string>> getTableContentOfAcademicYear(const AcademicYear& academicYear); // Done

Vector<Vector<string>> getTableContentOfSemester(const Semester& semester); // Done

Vector<Vector<string>> getTableContentOfListStudentInCourse(const Course& course); // Student and scoreboards // Done

// 

bool removeTable(Vector<Vector<string>>& table);

#endif // !DISPLAY_FUNCTION_H
