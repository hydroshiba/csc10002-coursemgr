#ifndef INSERT_FUNCTION_H
#define INSERT_FUNCTION_H

#include "Components.h"

/*		Insert function		*/

// Add new Student
bool addStudent(Vector<Student>& students, const std::string& ID, const std::string& firstName, const std::string& lastName, const std::string& genderStr, const std::string& birthStr, const std::string& socialID, const std::string& password, std::string& outStr);

// Add new staff
bool addStaff(std::string curStaffID, Vector<Staff>& staffs, const std::string& ID, const std::string& password, const std::string& firstName, const std::string& lastName, std::string& outStr);

// Add a new SchoolYear
bool addSchoolYear(Vector<SchoolYear>& yearList, const std::string& start, std::string& outStr); // Inputbox

// Add new class for SchoolYear
bool addClass(SchoolYear& schoolYear, const std::string& className, std::string& outStr); // Inputbox

// Add list student to class (from file)
bool importStudentListOfClassFromFile(Vector<Student> &students, Class& actClass, std::string& outStr); // By file

// Add a new students to class
bool addStudentToClass(Vector<Student>& students, Class& actClass, const std::string& studentID, std::string& outStr); // Only one student by InputBox

// Add a new academic year
bool addAcademicYear(Vector <AcademicYear>& newYear, const std::string& start, std::string& outStr); // Inputbox

// Add a semester to an academic year
bool addSemester(AcademicYear& newYear, const std::string& semesterID, std::string& outStr); // Inputbox

// Add a new course
bool addCourse(Semester& semester, const std::string& courseID, std::string& outStr); // Inputbox

// Add list student to course (from file)
bool importStudentListOfCourseFromFile(Vector<Student> &students, Course& course, std::string& outStr); // By file

// Add a student to course
bool addStudentToCourse(Vector<Student>& students, Course& course, const std::string& studentID, std::string& outStr); // Inputbox 

// ----------------------------------------------------------------------------------------------//

#endif // !INSERT_FUNCTION_H
