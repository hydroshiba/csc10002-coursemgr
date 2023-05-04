#ifndef IMPORT_EXPORT_FUNCTION_H
#define IMPORT_EXPORT_FUNCTION_H

#include "Components.h"

// Add list student to class (from file)
bool importStudentListOfClassFromFile(Vector<Student> &students, Class& actClass, std::string& outStr); // By file

// Add list student to course (from file)
bool importStudentListOfCourseFromFile(Vector<Student> &students, Course& course, std::string& outStr); // By file

// 19. export list of students in course to csv file
bool exportListOfStudent(Course& course);

// 20. import scoreboard of course
bool importScoreBoardOfCourse(Course& course);


#endif // ! IMPORT_EXPORT_FUNCTION_H
