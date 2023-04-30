#ifndef REMOVE_FUNCTION_H
#define REMOVE_FUNCTION_H

#include "Components.h"

/*		Remove function		*/

// Remove student from School
bool removeStudent(Vector<Student>& students, const string& studentID, string& outStr);

// Remove staff from school
bool removeStaff(string curStaffID, Vector<Staff>& staffs, const string& staffID, string& outStr);

// Remove list SchoolYear
bool removeListSchoolYear(Vector<SchoolYear>& schoolYears, string& outStr); // Button

// Remove SchoolYear
bool removeSchoolYear(Vector<SchoolYear>& schoolYears, const string& start, string& outStr); // Inputbox

// 
bool removeListClasses(SchoolYear& schoolYear, string& outStr);

// Remove Class from School
bool removeClass(Vector<SchoolYear>& schoolYears, const string& className, string& outStr); // Inputbox

//
bool removeListStudents(Class& thisClass, string& outStr);

// Remove list AcademicYear
bool removeListAcademicYear(Vector<AcademicYear>& academicYears, string& outStr); // Button

// Remove AcademicYear
bool removeAcademicYear(Vector<AcademicYear>& academicYears, const string& start, string& outStr); // Inputbox

//
bool removeListSemesters(AcademicYear& academicYear, string& outStr);

// Remove Semester
bool removeSemester(AcademicYear& academicYear, const string& semesterID, string& outStr); // Inputbox

//
bool removeListCourses(Semester& semester, string& outStr);

// Remove Course
bool removeCourse(Semester& semester, const string& courseID, string& outStr); // Inputbox

// Remove student from course
bool removeStudFromCourse(Course& course, const string& studentID, string& outStr); // Inputbox

// Free memory
bool freeMemory(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

//----------------------------------------------------------------------------------------------//

#endif // !REMOVE_FUNCTION_H
