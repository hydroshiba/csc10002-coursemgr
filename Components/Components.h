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

#include "ConvertType.h"

const std::string defaultStr = "Error";
/* Forward declaration of struct operator overloading */

template <typename Type>
bool operator!=(const Type &typeA, const Type &typeB) {
    return !(typeA == typeB);
}

//----------------------------------------------------------------------------------------------//

/*		Search function		*/
// Find student
Student* getStudent(Vector<SchoolYear>& schoolYears, const std::string& studentID);
// Find staff
Staff* getStaff(Vector<Staff> staffs, const std::string& staffID);
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
Scoreboard* getScoreboard(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears, const std::string& courseID, const std::string& studentID);

//----------------------------------------------------------------------------------------------//

/*		Insert function		*/

// Add a new SchoolYear
bool addNewSchoolYear(Vector<SchoolYear>& yearList, const std::string& start); // Inputbox
// Add a new SchoolYear
bool addNewSchoolYearV2(Vector<SchoolYear>& yearList, const unsigned int& start);
// Add new class for SchoolYear
bool addNewClass(SchoolYear &schoolYear, const std::string& className); // Inputbox
// Add students into a specific class
bool addStudToClass(Class &actClass); // By file
// Add a new students to class
bool addStudToClass(Class& actClass, const std::string& studentID); // Only one student by InputBox
// Add a new academic year
bool addNewAcademicYear(Vector <AcademicYear>& newYear, const std::string& start); // Inputbox
// Add a new academic year
bool addNewAcademicYearV2(Vector <AcademicYear>& newYear, const unsigned int& start);
// Add a semester to an academic year
bool addSemester(AcademicYear& newYear, const std::string& semesterID); // Inputbox
// Add a new course
bool addNewCourse(Semester& semester, const std::string& courseID); // Inputbox
// Add a student to course
bool addANewStudentToCourse(Vector<SchoolYear>& schoolYears, std::string& courseID, const std::string& studentID); // Inputbox
// Add a student to course
bool addANewStudentToCourse(Vector<SchoolYear>& schoolYears, Course& course, const std::string& studentID); // Inputbox but already have Course
// Add list student to course (from file)
bool getStudentToCourse(Vector<SchoolYear>& years, const std::string& courseID); // Only 1 student by Inputbox
// Add list student to course (from file)
bool getStudentToCourse(Vector<SchoolYear>& years, Course& course); // By file

// ----------------------------------------------------------------------------------------------//

/*		Remove function		*/

// Remove list SchoolYear
bool removeListSchoolYear(Vector<SchoolYear>& schoolYears); // Button
// Remove list AcademicYear
bool removeListAcademicYear(Vector<AcademicYear>& academicYears); // Button
// Remove SchoolYear
bool removeSchoolYear(Vector<SchoolYear>& schoolYears, const std::string& start); // Inputbox
// Remove SchoolYear
bool removeSchoolYearV2(Vector<SchoolYear>& schoolYears, const unsigned int& start);
// Remove AcademicYear
bool removeAcademicYear(Vector<AcademicYear>& academicYears, const std::string& start); // Inputbox
// Remove AcademicYear
bool removeAcademicYearV2(Vector<AcademicYear>& academicYears, const unsigned int& start);
// Remove Class from School
bool removeClass(Vector<SchoolYear>& schoolYears, const std::string& className); // Inputbox

bool removeListClasses(SchoolYear &schoolYear);
// Remove Student from School
bool removeStudent(Vector<SchoolYear>& schoolYears, const std::string& studentID); // Inputbox

bool removeListStudents(Class &thisClass);
// Remove Semester
bool removeSemester(Vector<AcademicYear>& academicYears, const std::string& semesterID); // Inputbox

bool removeListSemesters(AcademicYear& academicYear);
// Remove Course
bool removeCourse(Vector<AcademicYear>& academicYears, const std::string& courseID); // Inputbox

bool removeListCourses(Semester& semester);
// Remove student from course
bool removeStudFromCourse(Course& course, const std::string& studentID); // Inputbox
// Remove course from semester
bool deleteCourse(Semester& semester, const std::string& courseID); // Inputbox

// Free memory
bool freeMemory(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

//----------------------------------------------------------------------------------------------//

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
void updateSemester(Semester& semester, const int& option); // Inputbox
// Update Course
void updateCourse(Course& course, const int& option); // Inputbox
// Update Scoreboard
void updateScoreboard(Scoreboard& scoreboard, const int& option); // Inputbox
// 19. export list of students in course to csv file
void exportListOfStudent(Course& course);
// 20. import scoreboard of course
void importScoreBoardOfCourse(Course& course);
// 22. Update student result
void updateStudentResult(Student& student, std::string& courseID, const int& option); // Inputbox

//----------------------------------------------------------------------------------------------//

/*		Display function	*/

// View list of SchoolYear
void viewListSchoolYear(Vector<SchoolYear>& schoolYears); 
// 15. view list of classes
void viewListOfClasses(const SchoolYear & schoolYear, std::ostream & outDev);
// 16. view list of students in a class
void viewListOfStudentsInClass(const Class& curClass, std::ostream& outDev);

// View list of AcademicYear
void viewListAcademicYear(Vector<AcademicYear>& academicYears);
// View list of Semester
void viewListSemester(AcademicYear& academicYear);
// View list of courses
void viewCourses(Semester& sem, std::ostream& outDev);

// 17. view list of course
void viewListOfCoursesInSemester(const Semester& semester, std::ostream& outDev);
// 18. view list of students in course
void viewListOfStudentsInCourse(const Course& course, std::ostream& outDev);
// 21. view scoreboard of course
void viewScoreBoardOfCourse(Course& course);
// 14. view list of courses at current student
void viewListOfCoursesOfStudent(const Student& student, std::ostream& outDev = std::cout);

// 23. View scoreboard of class
void viewScoreboardOfClass(Class& curClass, const Semester& curSemester);
// 24. view scoreboard of student
void viewScoreBoardOfStudent(Student& student);

//----------------------------------------------------------------------------------------------//

/*		Fild and folder path function		*/

void createDirectoryIfNotExists(const std::string& dirPath);

std::string getListStaffFilePath();

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

void downloadListSchoolYearFolder(Vector<SchoolYear>& schoolYears);

void downloadSchoolYearFolder(SchoolYear& schoolYear);

void downloadListStaff(Vector<Staff>& staffs);

void downloadOutputStudClassFile(Class& actClass);

void downloadStudentFolder(Student& student);

void uploadAllData(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

void uploadListStaff(Vector<Staff> staffs);

void uploadListSchoolYearFolder(Vector <SchoolYear>& schoolYears);

void uploadSchoolYearFolder(SchoolYear& schoolYear);

void uploadStudentFolder(Class &actClass, Student &student, std::string id);

void get_students_priority(Class& actClass);

// AcademicYear

void downloadAllData(Vector <SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

void downloadListAcademicYearFolder(Vector<AcademicYear>& academicYears);

void downloadAcademicYearFolder(AcademicYear& academicYear);

void downloadSemesterFolder(Semester& semester);

void downloadCourseFolder(Course& course);

void dowdloadScoreboardFile(Course& course);

void uploadListAcademicYearFolder(Vector<SchoolYear>& schoolYears, Vector<AcademicYear>& academicYears);

void uploadAcademicYearFolder(Vector<SchoolYear>& schoolYears, AcademicYear& academicYear);

void uploadSemesterFolder(Vector<SchoolYear>& schoolYears, Semester& semester);

void uploadCourseFolder(Course& course);

//----------------------------------------------------------------------------------------------//

#endif