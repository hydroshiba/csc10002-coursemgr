#ifndef UPDATE_FUNCTION_H
#define UPDATE_FUNCTION_H

#include "Components.h"

/*		Update function		*/

// Update AcademicYear
void updateAcademicYear(AcademicYear& academicYear, const std::string& newStartYear); // Inputbox
// Update SchoolYear
void updateSchoolYear(SchoolYear& schoolYear, const std::string& newStartYear); // Inputbox
// Update Class
void updateClass(Class& CLASS, const std::string& newClassName); // Inputbox
// Update Student
void updateStudent(Student& student, const int& option); // Inputbox
// Update Semester
void updateSemester(Semester& semester, const std::string startDate, const std::string endDate); // Inputbox
// Update Course
void updateCourse(Course& course, const std::string& courseID, const std::string& classID, const std::string& name, const std::string& teacher, const std::string& cre, const std::string& maxEn, const std::string& day, const std::string& ss); // Inputbox
// Update Scoreboard
void updateScoreboard(Scoreboard& scoreboard, const int& option); // Inputbox
// 19. export list of students in course to csv file
void exportListOfStudent(Course& course);
// 20. import scoreboard of course
void importScoreBoardOfCourse(Course& course);
// 22. Update student result
void updateStudentResult(Course &course, const std::string studentID, const std::string midTerm, const std::string other, const std::string final, const std::string total); // Inputbox

//----------------------------------------------------------------------------------------------//

#endif // !UPDATE_FUNCTION_H
