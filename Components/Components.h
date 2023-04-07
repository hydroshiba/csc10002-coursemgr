#ifndef COMPONENT_H
#define COMPONENT_H

#include <iomanip>
#include <string>
#include "Vector.h"
#include <filesystem>

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

const std::string defaultStr = "Error";
/* Forward declaration of struct operator overloading */

template <typename Type>
bool operator!=(const Type &typeA, const Type &typeB) {
    return !(typeA == typeB);
}

/*			Convert enum to string function			*/
std::string weekday_to_string(const Weekday& weekday);
Weekday string_to_weekday(const std::string& str);
std::string session_to_string(const Session& session);
Session string_to_session(const std::string& str);
std::string gender_to_string(const Gender& gender);
Gender string_to_gender(const std::string& str);

//----------------------------------------------------------------------------------------------//

/*		Search function		*/
// Find student
Student* getStudent(Vector<SchoolYear>& schoolYears, const std::string& studentID);
// Find staff
Staff* getStaff(Vector<Staff> staffs, const std::string& staffID);
// Find SchoolYear
SchoolYear* getSchoolYear(Vector<SchoolYear>& schoolYears, const unsigned int& start);
// Find AcademicYear
AcademicYear* getAcademicYear(Vector<AcademicYear>& academicYears, const unsigned int& start);

//----------------------------------------------------------------------------------------------//

/*		Insert function		*/

// Add a new SchoolYear
void addNewSchoolYear(Vector<SchoolYear>& yearList);
// Add new class for SchoolYear
void addNewClass(Vector<SchoolYear>& yearList);
// Add students into a specific class
void addStudToClass(Class &actClass);
// Add a new academic year
void addNewAcademicYear(Vector <AcademicYear>& newYear);
// Add a semester to an academic year
void addNewSemester(AcademicYear& newYear);
// Add a student to course
void addANewStudentToCourse(Vector<SchoolYear>& schoolYears, Course& course);
// Add a new course
void addNewCourse(Semester& semester);
// Add list student to course (from file)
void addNewStudToCourse(Vector <SchoolYear>& yearlist, Course& course, std::istream& inDev = std::cin);
// Get students' info to course
void getStudentToCourse(Vector<SchoolYear>& years, Course& course);

// ----------------------------------------------------------------------------------------------//

/*		Remove function		*/

// Remove list SchoolYear
void removeListSchoolYear(Vector<SchoolYear>& schoolYears);
// Remove list AcademicYear
void removeListAcademicYear(Vector<AcademicYear>& academicYears);
// Remove SchoolYear
void removeSchoolYear(Vector<SchoolYear>& schoolYears, const unsigned int& start);
// Remove AcademicYear
void removeAcademicYear(Vector<AcademicYear>& academicYears, const unsigned int& start);
// Remove student from course
void removeStudFromCourse(Course& course);
// Remove course from semester
void deleteCourse(Semester& semester, const std::string& courseID);

//----------------------------------------------------------------------------------------------//

/*		Update function		*/

// Update course informations
void updateCourse(Course& course);
// 19. export list of students in course to csv file
void exportListOfStudent(Course& course);
// 20. import scoreboard of course
void importScoreBoardOfCourse(Course& course);
// 22. Update student result
void updateStudentResult(Student& student);

//----------------------------------------------------------------------------------------------//

/*		Display function	*/

// View list of courses
void viewCourses(Semester& sem, std::ostream& outDev);
// 14. view list of courses at current student
void viewListOfCoursesOfStudent(const Student& student, std::ostream& outDev = std::cout);
// 15. view list of classes 
void viewListOfClasses(const SchoolYear& schoolYear, std::ostream& outDev);
// 16. view list of students in a class
void viewListOfStudentsInClass(const Class& curClass, std::ostream& outDev);
// 17. view list of course
void viewListOfCoursesInSemester(const Semester& semester, std::ostream& outDev);
// 18. view list of students in course
void viewListOfStudentsInCourse(const Course& course, std::ostream& outDev);
// 21. view scoreboard of course
void viewScoreBoardOfCourse(Course& course);
// 23. View scoreboard of class
void viewScoreboardOfClass(Class& curClass, const Semester& curSemester);
// 24. view scoreboard of student
void viewScoreBoardOfStudent(Student& student);

//----------------------------------------------------------------------------------------------//

/*		Fild and folder path function		*/

void createDirectoryIfNotExists(const std::string& dirPath);

std::string getListSchoolYearFilePath();

std::string getListAcademicYearFilePath();

std::string getSchoolYearFolderPath(const SchoolYear& schoolyear);

std::string getInputSchoolYearFilePath(const SchoolYear& schoolyear);

std::string getClassFolderPath(const Class& CLASS);

std::string getInputStudClassFilePath(const Class& CLASS);

std::string getOutputStudClassFilePath(const Class& CLASS);

std::string getInputScoreClassFilePath(const Class& CLASS);

std::string getStudentFolderPath(const Student& student);

std::string getOutputScoreStudentFilePath(const Student& student);

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

//----------------------------------------------------------------------------------------------//

/*			Upload and download function		*/

// SchoolYear

void downloadListSchoolYearFolder(Vector <SchoolYear>& schoolYears);

void downloadSchoolYearFolder(SchoolYear& schoolYear);

void downloadOutputStudClassFile(Class& actClass);

void downloadStudentFolder(Student& student);

// AcademicYear

void downloadListAcademicYearFolder(Vector<AcademicYear>& academicYears);

void downloadAcademicYearFolder(AcademicYear& academicYear);

void downloadSemesterFolder(Semester& semester);

void downloadCourseFolder(Course& course);

void dowdloadScoreboardFile(Course& course);

void uploadListSchoolYearFolder(Vector <SchoolYear>& schoolYears);

void uploadSchoolYearFolder(SchoolYear& schoolYear);

void uploadOutputStudClassFile(Class& actClass);

void uploadListAcademicYearFolder(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

void uploadAcademicYearFolder(Vector<SchoolYear>& schoolYears, AcademicYear& academicYear);

void uploadSemesterFolder(Vector<SchoolYear>& schoolYears, Semester& semester);

void uploadCourseFolder(Course& course);

//----------------------------------------------------------------------------------------------//

#endif