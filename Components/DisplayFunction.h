#ifndef DISPLAY_FUNCTION_H
#define DISPLAY_FUNCTION_H

#include <iostream>
#include <fstream>

#include "Components.h"

/*		Display function	*/

// DropBox
Vector<std::string> getListSchoolYear(Vector<SchoolYear>& schoolYears);

// DropBox
Vector<std::string> getListAcademicYear(Vector<AcademicYear>& academicYears);

// DropBox
Vector<std::string> getListClass(const SchoolYear& schoolYear);

// DropBox
Vector<std::string> getListSemester(const AcademicYear& academicYear);

// DropBox
Vector<std::string> getListCourse(const Semester& semester);

// Table
Vector<Vector<std::string>> getTableContentOfScoreboardsofStudent(const Student& student);

#endif // !DISPLAY_FUNCTION_H
