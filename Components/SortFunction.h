#ifndef SORT_FUNCTION_H
#define SORT_FUNCTION_H

#include "Components.h"

void sortStudentList(Vector<Student>& students, const int& left, const int& right);

void sortStaffList(Vector<Staff>& staffs, const int& left, const int& right);

void sortSchoolYearList(Vector<SchoolYear>& schoolYears, const int& left, const int& right);

void sortAcademicYearList(Vector<AcademicYear>& academicYears, const int& left, const int& right);

void sortSemesters(Vector<Semester>& semesters, const int& left, const int& right);

void sortClasses(Vector<Class>& classes, const int& left, const int& right);

void sortCourses(Vector<Course>& courses, const int& left, const int& right);

void sortStudentsInClass(Class& CLASS, const int& left, const int& right);
#endif // !SORT_FUNCTION_H

