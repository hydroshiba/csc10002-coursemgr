#ifndef REMOVE_FUNCTION_H
#define REMOVE_FUNCTION_H

#include "Components.h"

/*		Remove function		*/

// Remove student from School
bool removeStudent(Vector<Student>& students, const string& studentID, string& outStr);
// Remove staff from school
bool removeStaff(string curStaffID, Vector<Staff>& staffs, const string& staffID, string& outStr);
// Remove list SchoolYear
bool removeListSchoolYear(Vector<SchoolYear>& schoolYears); // Button
// Remove list AcademicYear
bool removeListAcademicYear(Vector<AcademicYear>& academicYears); // Button
// Remove SchoolYear
bool removeSchoolYear(Vector<SchoolYear>& schoolYears, const string& start); // Inputbox
// Remove SchoolYear
bool removeSchoolYearV2(Vector<SchoolYear>& schoolYears, const unsigned int& start);
// Remove AcademicYear
bool removeAcademicYear(Vector<AcademicYear>& academicYears, const string& start); // Inputbox
// Remove AcademicYear
bool removeAcademicYearV2(Vector<AcademicYear>& academicYears, const unsigned int& start);
// Remove Class from School
bool removeClass(Vector<SchoolYear>& schoolYears, const string& className); // Inputbox

bool removeListClasses(SchoolYear& schoolYear);
// Remove Student from School
bool removeStudent(Vector<SchoolYear>& schoolYears, const string& studentID); // Inputbox

bool removeListStudents(Class& thisClass);
// Remove Semester
bool removeSemester(Vector<AcademicYear>& academicYears, const string& semesterID); // Inputbox

bool removeListSemesters(AcademicYear& academicYear);
// Remove Course
bool removeCourse(Vector<AcademicYear>& academicYears, const string& courseID); // Inputbox

bool removeListCourses(Semester& semester);
// Remove student from course
bool removeStudFromCourse(Course& course, const string& studentID, string& outStr); // Inputbox
// Remove course from semester
bool deleteCourse(Semester& semester, const string& courseID); // Inputbox

// Free memory
bool freeMemory(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

//----------------------------------------------------------------------------------------------//

#endif // !REMOVE_FUNCTION_H
