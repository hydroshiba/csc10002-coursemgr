#ifndef SEARCH_FUNCTION_H
#define SEARCH_FUNCTION_H

#include "Components.h"

/*		Search function		*/

// Find student
Student* getStudent(const string& studentID);

// Find staff
Staff* getStaff(const string& staffID);

// Find SchoolYear
SchoolYear* getSchoolYear(const string& start);

// Find AcademicYear
AcademicYear* getAcademicYear(const string& start);

// Find Class
Class* getClass(SchoolYear& schoolYear, const string& className);

Semester* getSemester(const string& semesterID); 

// Find Semester
Semester* getSemester(AcademicYear& academicYear, const string& semesterID);

// Find Course
Course* getCourse(Semester& semester, const string& courseID);

// Find Scoreboard of Course of Student
Scoreboard* getScoreboard(Course& course, const string& studentID);

// Check student acc
bool isCorrectStaffAccount(const string& staffID, const string& password, string& outStr);

// Check staff acc
bool isCorrectStudentAccount(const string& studentID, const string& password, string& outStr);

//----------------------------------------------------------------------------------------------//

#endif