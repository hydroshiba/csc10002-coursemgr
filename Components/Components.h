#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include "Structures.h"
#include <iomanip>

#include "Date.h"
#include "Name.h"
#include "User.h"

#include "SchoolYear.h"
#include "Class.h"

#include "AcademicYear.h"
#include "Semester.h"
#include "Course.h"

#include "Student.h"
#include "Scoreboard.h"

/* Enumerators */

enum Weekday { SUN, MON, TUE, WED, THU, FRI, SAT };
enum Gender { male, female };
enum Session { S1, S2, S3, S4 };

/* Structures forward declaration */

struct Date;
struct Name;
struct Scoreboard;

struct User;
struct Staff;
struct Student;

struct AcademicYear;
struct Semester;
struct Course;

struct SchoolYear;
struct Class;

// 1. Add a new 1st-year & delete old 4th-year
void addNewSchoolYear(Vector<SchoolYear>& yearList);

// 2. Add several classes for 1st year
void addClasses(Vector<SchoolYear>& yearList);

// 3-4-5 Add students into a specific class
void addStudToClass(Class& actClass, const std::string inFile);

// 6. Add a new academic year
void addNewAcademicYear(AcademicYear& newYear);

// 6. Add a semester to an academic year
void addSemester(AcademicYear& newYear);

// 7. Add a new course
void addNewCourse(Semester& semester);

// 8. Get students' info to course
void getStudentToCourse(Vector<SchoolYear> years, Course& course, const std::string stud_input_file);

// 9. View list of courses
void viewCourses(Semester sem, std::ostream& outDev = std::cout);

// 10. Update course informations
void updateCourse(Course& course);

// 11. Add student to course
void addNewStudToCourse(Vector <SchoolYear>& yearlist, Course& course, std::istream& inDev = std::cin);

// 12. Remove student from course
void removeStudFromCourse(Course& course, std::istream& inDev = std::cin);
// 13. delete course in current semester 
bool deleteCourse(Semester& semester, const std::string& courseID);

// 14. view list of courses at current student
void viewListOfCoursesOfStudent(const Student& student, std::ostream& outDev = std::cout);

// 15. view list of classes 
void viewListOfClasses(const SchoolYear& schoolYear, std::ostream& outDev = std::cout);

// 16. view list of students in a class
void viewListOfStudentsInClass(const Class& curClass, std::ostream& outDev = std::cout);

// 17. view list of course
void viewListOfCoursesInSemester(Semester& semester, std::ostream& outDev = std::cout);

// 18. view list of students in course
void viewListOfStudentsInCourse(const Course& course, std::ostream& outDev = std::cout);

// 19. export list of students in course to csv file
void exportListOfStudent(Course& course, const std::string& fileName);

// 20. import scoreboard of course
void importScoreBoardOfCourse(Course& course);

// 21. view scoreboard of course
void viewScoreBoardOfCourse(Course& course);

// 22. Update student result
void updateStudentResult(Student& student);

// 23. View scoreboard of class
void viewScoreboardOfClass(Class& curClass, const Semester& curSemester);

// 24. view scoreboard of student
void viewScoreBoardOfStudent(Student& student);

/* Forward declaration of struct operator overloading */

template <typename Type>
bool operator!=(const Type &typeA, const Type &typeB) {
    return !(typeA == typeB);
}



#endif
