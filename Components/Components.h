#ifndef COMPONENT_H
#define COMPONENT_H

#include <iomanip>
#include <string>
#include "Vector.h"

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

struct Compare {

};

/* Forward declaration of struct operator overloading */

template <typename Type>
bool operator!=(const Type &typeA, const Type &typeB) {
    return !(typeA == typeB);
}

// Convert enum to string
std::string weekday_to_string(const Weekday& weekday);

Weekday string_to_weekday(const std::string& str);

// 1 - 12

void addNewSchoolYear(Vector<SchoolYear>& yearList);
void addClasses (Vector<SchoolYear>& yearList);
void addStudToClass(Class &actClass,const std::string inFile);
void addNewAcademicYear(Vector <AcademicYear> &newYear);

void addSemester(AcademicYear &newYear);
void addNewCourse(Semester &semester);
void getStudentToCourse(Vector<SchoolYear> years, Course &course, const std::string stud_input_file);
void viewCourses(Semester sem, std::ostream& outDev = std::cout);

void updateCourse(Course &course);
void addNewStudToCourse(Vector <SchoolYear>& yearlist, Course &course, std::istream& inDev = std::cin);
void removeStudFromCourse(Course &course, std::istream &inDev = std::cin);

// 13 - 24

void deleteCourse(Semester& semester, const std::string& courseID);
void viewListOfCoursesOfStudent(const Student& student, std::ostream& outDev = std::cout);
void viewListOfClasses(const SchoolYear& schoolYear, std::ostream& outDev = std::cout);
void viewListOfStudentsInClass(const Class& curClass, std::ostream& outDev = std::cout);

void viewListOfCoursesInSemester(const Semester& semester, std::ostream& outDev = std::cout);
void viewListOfStudentsInCourse(const Course& course, std::ostream& outDev = std::cout);
void exportListOfStudent(Course& course, const std::string& fileName);
void importScoreBoardOfCourse(Course& course);

void viewScoreBoardOfCourse(Course& course);
void updateStudentResult(Student& student);
void viewScoreboardOfClass(Class& curClass, const Semester& curSemester);
void viewScoreBoardOfStudent(Student& student);

// Get file path in Data Folder
std::string getListSchoolYearFilePath();

std::string getListAcademicYearFilePath();

std::string getSchoolYearFolderPath(const SchoolYear& schoolyear);

std::string getInputSchoolYearFilePath(const SchoolYear& schoolyear);

std::string getClassFolderPath(const Class& CLASS);

std::string getInputStudClassFilePath(const Class& CLASS);

std::string getInputScoreClassFilePath(const Class& CLASS);

std::string getStudentFolderPath(const Student& student);

std::string getInputStudentFilePath(const Student& student);

std::string getInputStandardIn4StudentFilePath(const Student& student);

std::string getAcademicYearFolderPath(const AcademicYear& academicYear);

std::string getAcademicYearFilePath(const AcademicYear& academicYear);

std::string getSemesterFolderPath(const Semester& semester);

std::string getSemesterFilePath(const Semester& semester);

std::string getCourseFolderPath(const Course& course);

std::string getCourseFilePath(const Course& course);

std::string getInputListStudCourseFilePath(const Course& course);

std::string getOutputListStudCourseFilePath(const Course& course);

std::string getInputScoreCourseFilePath(const Course& course);

std::string getOutputScoreStudCourseFilePath(const Course& course);

void downloadListSchoolYearFolder(Vector <SchoolYear>& schoolYears);

void downloadSchoolYearFolder(SchoolYear &schoolYear);

void downloadListAcademicYearFolder(Vector<AcademicYear>& academicYears);

void downloadAcademicYearFolder(AcademicYear& academicYear);

void downloadSemesterFolder(Semester& semester);

void downloadCourseFolder(Course& course);

void dowdloadScoreboardFile(Course& course);

#endif