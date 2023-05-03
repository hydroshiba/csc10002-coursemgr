#ifndef DOWNLOAD_FUNCTION_H
#define DOWNLOAD_FUNCTION_H

#include "Components.h"
#include "User.h"

bool downloadListSchoolYearFolder();

bool downloadSchoolYearFolder(SchoolYear& schoolYear);

bool downloadListStaff();

bool downloadListStudent();
// Download Student ID In Class
bool downloadDataStudClassFile(Class& actClass);

bool downloadStudentFolder(Student& student);

bool downloadAllData(Vector<Staff::User>& staffs, Vector<Student>& students, Vector <SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

bool downloadListAcademicYearFolder(Vector<AcademicYear>& academicYears);

bool downloadAcademicYearFolder(AcademicYear& academicYear);

bool downloadSemesterFolder(Semester& semester);

bool downloadCourseFolder(Course& course);

bool downloadScoreboardFile(Course& course);

#endif // !DOWNLOAD_FUNCTION_H
