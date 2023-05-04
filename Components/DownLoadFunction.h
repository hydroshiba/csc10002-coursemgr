#ifndef DOWNLOAD_FUNCTION_H
#define DOWNLOAD_FUNCTION_H

#include "Components.h"
#include "User.h"

bool downloadAllData();

bool downloadListStaff();

bool downloadListStudent();

bool downloadListSchoolYear();

bool downloadSchoolYear(SchoolYear& schoolYear);

bool downloadClass(Class& CLASS);

bool downloadListAcademicYear();

bool downloadAcademicYear(AcademicYear& academicYear);

bool downloadSemester(Semester& semester);

bool downloadCourse(Course& course);

#endif // !DOWNLOAD_FUNCTION_H
