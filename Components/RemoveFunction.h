#ifndef REMOVE_FUNCTION_H
#define REMOVE_FUNCTION_H

#include "Components.h"

/*		Remove function		*/

// Remove list SchoolYear
bool removeListSchoolYear(Vector<SchoolYear>& schoolYears); // Button
// Remove list AcademicYear
bool removeListAcademicYear(Vector<AcademicYear>& academicYears); // Button
// Remove SchoolYear
bool removeSchoolYear(Vector<SchoolYear>& schoolYears, const std::string& start); // Inputbox
// Remove SchoolYear
bool removeSchoolYearV2(Vector<SchoolYear>& schoolYears, const unsigned int& start);
// Remove AcademicYear
bool removeAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start); // Inputbox
// Remove AcademicYear
bool removeAcademicYearV2(Vector<AcademicYear>& academicYears, const unsigned int& start);
// Remove Class from School
bool removeClass(Vector<SchoolYear>& schoolYears, const std::string& className); // Inputbox

bool removeListClasses(SchoolYear& schoolYear);
// Remove Student from School
bool removeStudent(Vector<SchoolYear>& schoolYears, const std::string& studentID); // Inputbox

bool removeListStudents(Class& thisClass);
// Remove Semester
bool removeSemester(Vector<AcademicYear>& academicYears, const std::string& semesterID); // Inputbox

bool removeListSemesters(AcademicYear& academicYear);
// Remove Course
bool removeCourse(Vector<AcademicYear>& academicYears, const std::string& courseID); // Inputbox

bool removeListCourses(Semester& semester);
// Remove student from course
bool removeStudFromCourse(Course& course, const std::string& studentID); // Inputbox
// Remove course from semester
bool deleteCourse(Semester& semester, const std::string& courseID); // Inputbox

// Free memory
bool freeMemory(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

//----------------------------------------------------------------------------------------------//

#endif // !REMOVE_FUNCTION_H