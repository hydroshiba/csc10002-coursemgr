#ifndef UPDATE_FUNCTION_H
#define UPDATE_FUNCTION_H

#include "Components.h"

/*		Update function		*/

// Update student in4
bool updateStudentIn4(Student& student, const string& ID, const string& firstName, const string& lastName, const string& genderStr, const string& birthStr, const string& socialID, const string& password, string& outStr);

// Update staff in4
bool updateStaffIn4(Staff& staff, const string& ID, const string& firstName, const string& lastName, const string& password, string& outStr);

// Update SchoolYear
void updateSchoolYear(SchoolYear& schoolYear, const string& newStartYear, string& outStr); // Inputbox

// Update Class
void updateClass(Class& CLASS, const string& newClassName, string& outStr); // Inputbox

// Update AcademicYear 
void updateAcademicYear(AcademicYear& academicYear, const string& newStartYear, string& outStr); // Inputbox

// Update Semester
void updateSemester(Semester& semester, const string startDate, const string endDate, string& outStr); // Inputbox

// Update Course
bool updateCourse(Course& course, const string& courseID, const string& classID, const string& name, const string& teacher, const string& cre, const string& maxEnroll, const string& day, const string& ss, string &outStr); // Inputbox

// Update student result
void updateScoreboard(Course& course, const string& studentID, const string& midTerm, const string& other, const string& final, const string& total, string& outStr); // Inputbox

// 19. export list of students in course to csv file
void exportListOfStudent(Course& course);
// 20. import scoreboard of course
void importScoreBoardOfCourse(Course& course);


//----------------------------------------------------------------------------------------------//

#endif // !UPDATE_FUNCTION_H
