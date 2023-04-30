#ifndef DISPLAY_FUNCTION_H
#define DISPLAY_FUNCTION_H

#include <iostream>
#include <fstream>

#include "Components.h"

/*		Display function	*/

Vector<std::string> getListSchoolYear(Vector<SchoolYear>& schoolYears);

Vector<std::string> getListAcademicYear(Vector<AcademicYear>& academicYears);

Vector<std::string> getListClass(const SchoolYear& schoolYear);

Vector<std::string> getListSemester(const AcademicYear& academicYear);

Vector<std::string> getListCourse(const Semester& semester);

Vector<Vector<std::string>> getTableContentOfScoreboardsofStudent(const Student& student);

//----------------------------------------------------------------------------------------------//

#endif // !DISPLAY_FUNCTION_H
