#ifndef SEARCH_FUNCTION_H
#define SEARCH_FUNCTION_H

#include "Components.h"

/*		Search function		*/

// Find student
Student* getStudent(Vector<Student>& students, const string& studentID);

// Find staff
Staff* getStaff(Vector<Staff>& staffs, const string& staffID);

// Find SchoolYear
SchoolYear* getSchoolYear(Vector<SchoolYear>& schoolYears, const string& start);

// Find AcademicYear
AcademicYear* getAcademicYear(Vector<AcademicYear>& academicYears, const string& start);

// Find Class
Class* getClass(SchoolYear& schoolYear, const string& className);

// Find Semester
Semester* getSemester(AcademicYear& academicYear, const string& semesterID);

// Find Course
Course* getCourse(Semester& semester, const string& courseID);

// Find Scoreboard of Course of Student
Scoreboard* getScoreboard(Course& course, const string& studentID);

// Check student acc
bool isCorrectStaffAccount(Vector<Staff>& staffs, const string& staffID, const string& password, string& outStr);

// Check staff acc
bool isCorrectStudentAccount(Vector<Student>& students, const string& studentID, const string& password, string& outStr);

//----------------------------------------------------------------------------------------------//

#endif