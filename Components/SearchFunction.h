#ifndef SEARCH_FUNCTION_H
#define SEARCH_FUNCTION_H

#include "Components.h"

/*		Search function		*/
// Find student
Student* getStudent(Vector<Student>& students, const std::string& studentID);
// Find staff
Staff* getStaff(Vector<Staff>& staffs, const std::string& staffID);
// Find SchoolYear
SchoolYear* getSchoolYear(Vector<SchoolYear>& schoolYears, const std::string& start);
// Find SchoolYear
SchoolYear* getSchoolYear(Vector<SchoolYear>& schoolYears, const unsigned int& start);
// Find AcademicYear
AcademicYear* getAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start);
// Find AcademicYear
AcademicYear* getAcademicYear(Vector<AcademicYear>& academicYears, const unsigned int& start);
// Find Class
Class* getClass(Vector<SchoolYear>& schoolYears, const std::string& className);
// Find Semester
Semester* getSemester(Vector<AcademicYear>& academicYears, const std::string& semesterID);
// Find Course
Course* getCourse(Vector<AcademicYear>& academicYears, const std::string& courseID);
// Find Scoreboard of Course of Student
Scoreboard* getScoreboard(Vector<AcademicYear>& academicYears, const std::string& courseID, const std::string& studentID);
// Check student acc
bool isCorrectStaffAccount(Vector<Staff>& staffs, const std::string& staffID, const std::string& password, std::string& outStr);
// Check staff acc
bool isCorrectStudentAccount(Vector<Student>& students, const std::string& studentID, const std::string& password, std::string& outStr);
// Check student
bool isStudent(Vector<Student>& students, const std::string& studentID, std::string& outStr);
// Check staff
bool isStaff(Vector<Staff>& staffs, const std::string& staffID, std::string& outStr);
// Check SchoolYear
bool isSchoolYear(Vector<SchoolYear>& schoolYears, const std::string& start, std::string& outStr);
// Check AcademicYear
bool isAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start, std::string& outStr);
// Check Class
bool isClass(Vector<SchoolYear>& schoolYears, const std::string& className, std::string& outStr);
// Check Semester
bool isSemester(Vector<AcademicYear>& academicYears, const std::string& semesterID, std::string& outStr);
// Check Course
bool isCourse(Vector<AcademicYear>& academicYears, const std::string& courseID, std::string& outStr);

//----------------------------------------------------------------------------------------------//

#endif