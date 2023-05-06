#ifndef INSERT_FUNCTION_H
#define INSERT_FUNCTION_H

#include "Components.h"

/*		Insert function		*/

// Add new Student
bool addStudent(const string& ID, const string& firstName, const string& lastName, const string& genderStr, const string& birthStr, const string& socialID, const string& password, string& outStr);

// Add new staff
bool addStaff(string curStaffID, const string& ID, const string& password, const string& firstName, const string& lastName, string& outStr);

// Add a new SchoolYear
bool addSchoolYear(const string& start, string& outStr); // Inputbox

// Add new class for SchoolYear
bool addClass(SchoolYear& schoolYear, const string& className, string& outStr); // Inputbox

// Add a new students to class
bool addStudentToClass(Class& actClass, const string& studentID, string& outStr); // Only one student by InputBox

// Add a new academic year
bool addAcademicYear(const string& start, string& outStr); // Inputbox

// Add a semester to an academic year
bool addSemester(AcademicYear& newYear, const string& semesterID, string& outStr); // Inputbox

// Add a new course
bool addCourse(Semester& semester, const string& courseID, string& outStr); // Inputbox

// Add a student to course
bool addStudentToCourse(Course& course, const string& studentID, string& outStr); // Inputbox 

// ----------------------------------------------------------------------------------------------//

#endif // !INSERT_FUNCTION_H
