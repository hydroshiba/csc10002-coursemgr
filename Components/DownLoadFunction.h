#ifndef DOWNLOAD_FUNCTION_H
#define DOWNLOAD_FUNCTION_H

#include "Components.h"

void downloadListSchoolYearFolder(Vector<SchoolYear>& schoolYears);

void downloadSchoolYearFolder(SchoolYear& schoolYear);

void downloadListStaff(Vector<Staff>& staffs);

void downloadListStudent(Vector<Student>& students);

void downloadOutputStudClassFile(Class& actClass);

void downloadStudentFolder(Student& student);

void downloadAllData(Vector<Student> students, Vector <SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

void downloadListAcademicYearFolder(Vector<AcademicYear>& academicYears);

void downloadAcademicYearFolder(AcademicYear& academicYear);

void downloadSemesterFolder(Semester& semester);

void downloadCourseFolder(Course& course);

void dowdloadScoreboardFile(Course& course);



#endif // !DOWNLOAD_FUNCTION_H
