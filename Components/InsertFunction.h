#ifndef INSERT_FUNCTION_H
#define INSERT_FUNCTION_H

#include "Components.h"

/*		Insert function		*/

// Add new staff
bool addStaff(Vector<Staff>& staffs, const std::string& ID, const std::string& password, const std::string& firstName, const std::string& lastName, std::string& outStr);
// Add a new SchoolYear
bool addSchoolYear(Vector<SchoolYear>& yearList, const std::string& start, std::string& outStr); // Inputbox
// Add a new SchoolYear
bool addSchoolYear(Vector<SchoolYear>& yearList, const unsigned int& start, std::string& outStr);
// Add new class for SchoolYear
bool addClass(SchoolYear& schoolYear, const std::string& className, std::string& outStr); // Inputbox
// Add students into a specific class (from File)
bool addStudToClass(Vector<Student> &students, Class& actClass, std::string& outStr); // By file
// Add a new students to class
bool addStudToClass(Vector <Student>& students, Class& actClass, const std::string& studentID, std::string& outStr); // Only one student by InputBox
// Add a new academic year
bool addAcademicYear(Vector <AcademicYear>& newYear, const std::string& start, std::string& outStr); // Inputbox
// Add a new academic year
bool addAcademicYear(Vector <AcademicYear>& newYear, const unsigned int& start, std::string& outStr);
// Add a semester to an academic year
bool addSemester(AcademicYear& newYear, const std::string& semesterID, const std::string& startDay, const std::string &startMonth, const std::string& startYear, const std::string &endDay, const std::string &endMonth, const std::string &endYear, std::string& outStr); // Inputbox
// Add a new course
bool addCourse(Semester& semester, const std::string& courseID, std::string& outStr); // Inputbox
// Add list student to course (from file)
bool getStudentToCourse(Vector<Student> &students, Course& course, std::string& outStr); // By file
// Add list student to course (from file)
bool getStudentToCourse(Vector<SchoolYear>& years, const std::string& courseID, std::string& outStr); // Already have course
// Add a student to course
bool addAStudentToCourse(Vector<SchoolYear>& schoolYears, std::string& courseID, const std::string& studentID, std::string& outStr); // Inputbox
// Add a student to course
bool addAStudentToCourse(Vector<SchoolYear>& schoolYears, Course& course, const std::string& studentID, std::string& outStr); // Inputbox but already have Course

// ----------------------------------------------------------------------------------------------//

#endif // !INSERT_FUNCTION_H
