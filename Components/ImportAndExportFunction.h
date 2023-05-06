#ifndef IMPORT_EXPORT_FUNCTION_H
#define IMPORT_EXPORT_FUNCTION_H

#include "Components.h"

// Add list student to class (from file) 
// ClassScene
bool importStudentListOfClassFromFile(const string& filename, Vector<Student> &students, Class& actClass, string& outStr); // By file
// Add list student to course (from file)
// CourseScene
bool importStudentListOfCourseFromFile(const string& filename, Vector<Student> &students, Course& course, string& outStr); // By file
// 19. export list of students in course to csv file
// CourseScene
bool exportListOfStudentInCourse(const string& filename, Course& course, string& outStr);
// 20. import scoreboard of course
// CourseScene
bool importScoreBoardOfCourse(const string& filename, Course& course);
// Student Scene
bool exportListScoreboardOfStudent(const string& filename, Student& student, string& outStr);
// StudentScene
bool exportListScoreboardInSemesterOfStudent(const string& filename, Student& student, Semester& semester, string& outStr);


// Optional
// Staff scene
bool exportListSchoolYear(const string& filename, string& outStr);
// SchoolYear Scene
bool exportListClassInSchoolYear(const string& filename, SchoolYear& schoolYear, string& outStr);
// Class scene
bool exportListStudentInClass(const string& filename, Class& CLASS, string& outStr);
// Class scene
bool exportListScoreboardInSemesterOfClass(const string& filename, Class& CLASS, Semester& semester, string& outStr);
// class scene
bool exportListScoreboardOfClass(const string& filename, Class& CLASS, string& outStr);
// Staff Scene
bool exportListAcademicYear(const string& filename, string& outStr);
// AcademicYear scene
bool exportListSemesterInAcademicYear(const string& filename, AcademicYear& academicYear, string& outStr);
// Semester scene
bool exportListCourseInSemester(const string& filename, Semester& semester, string& outStr);
// Course scene
bool exportListScoreboardOfCourse(const string& filename, Course& course, string& outStr);

#endif // ! IMPORT_EXPORT_FUNCTION_H
