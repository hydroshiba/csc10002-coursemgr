#ifndef REMOVE_FUNCTION_H
#define REMOVE_FUNCTION_H

#include "Components.h"

/*		Remove function		*/

// Remove student list - Free memory
bool removeListStudent();

// Remove staff list - Free memory
bool removeListStaff();

// Remove list SchoolYear - Free memory
bool removeListSchoolYear();

// Remove list AcademicYear - Free memory
bool removeListAcademicYear();

// Free memory
bool freeMemory();

// Remove student from School
bool removeStudent(const string& studentID, string& outStr);

// Remove staff from school
bool removeStaff(string curStaffID, const string& staffID, string& outStr);

// Remove SchoolYear
bool removeSchoolYear(const string& start, string& outStr); 

// Remove Class from School
bool removeClass(SchoolYear& schoolYears, const string& className, string& outStr); 

// Remove a student from class
bool removeStudentFromClass(Class& CLASS, const string& studentID, string& outStr);

// Remove AcademicYear
bool removeAcademicYear(const string& start, string& outStr);

// Remove Semester
bool removeSemester(AcademicYear& academicYear, const string& semesterID, string& outStr);

// Remove Course
bool removeCourse(Semester& semester, const string& courseID, string& outStr); 

// Remove student from course
bool removeStudFromCourse(Course& course, const string& studentID, string& outStr); 

//----------------------------------------------------------------------------------------------//

#endif // !REMOVE_FUNCTION_H
