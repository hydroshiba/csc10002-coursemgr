#include "FileAndDirFunction.h"


#include "Date.h"
#include "Name.h"
#include "User.h"

#include "SchoolYear.h"
#include "Class.h"
#include "Student.h"

#include "AcademicYear.h"
#include "Semester.h"
#include "Course.h"
#include "Scoreboard.h"

/*		Fild and folder path function		*/

void createDirectoryIfNotExists(const string& dirPath)
{
	if (!std::filesystem::exists(dirPath)) {
		std::filesystem::create_directory(dirPath);
		std::cout << "Create directory " << dirPath << std::endl;
	}
}

string getLoadedFilePath(){
	string dirPath = "Data/LoadedFile/";
	createDirectoryIfNotExists(dirPath);
	return dirPath;
}

string getListStaffFilePath(){
	return getLoadedFilePath() + "StaffList.csv";
}

string getListStudentFilePath(){
	return getLoadedFilePath() + "StudentList.csv";
}

string getListSchoolYearFilePath() {
	return getLoadedFilePath() + "ListSchoolYear.csv";
}

string getListAcademicYearFilePath() {
	return getLoadedFilePath() + "ListAcademicYear.csv";
}

string getSchoolYearFolderPath(const SchoolYear& schoolyear) {
	string schoolYearDirPath = "Data/SchoolYear/HCMUS_" + std::to_string(schoolyear.start) + "/";
	createDirectoryIfNotExists(schoolYearDirPath);
	return schoolYearDirPath;
}

string getSchoolYearFilePath(const SchoolYear& schoolyear) {
	return getLoadedFilePath() + "HCMUS_" + std::to_string(schoolyear.start) + ".csv";
}

string getClassFolderPath(const Class& CLASS) {
	string schoolYearFolderPath = getSchoolYearFolderPath(*(CLASS.ptrSchoolYear));
	string classFolderPath = schoolYearFolderPath + CLASS.name + "/";
	createDirectoryIfNotExists(classFolderPath);
	return classFolderPath;
}

string getClassFilePath(const Class& CLASS) {
	return getLoadedFilePath() + CLASS.name + ".csv";
}


string getInputStudClassFilePath(const Class& CLASS) {
	string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + "_InputStud.csv";
}

string getDataStudClassFilePath(const Class& CLASS) {
	string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + "_StudData.csv";
}


string getInputScoreClassFilePath(const Class& CLASS) {
	string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + "_OutputScore.csv";
}

string getStudentFolderPath(const Student& student) {
	string classFolderPath = getClassFolderPath(*(student.ptrClass));
	string studentFolderPath = classFolderPath + "Students/" + student.ID + "/";
	createDirectoryIfNotExists(studentFolderPath);
	return studentFolderPath;
}

string getOutputScoreStudentFilePath(const Student& student) {
	string studentFolderPath = getStudentFolderPath(student);
	return studentFolderPath + student.ID + "_OutputScore.csv";
}

string getInputStandardIn4StudentFilePath(const Student& student) {
	string studentFolderPath = getStudentFolderPath(student);
	return studentFolderPath + student.ID + "_OutputStdIn4.csv";
}

string getAcademicYearFolderPath(const AcademicYear& academicYear) {
	string academicYearFolderPath = "Data/AcademicYear/" + std::to_string(academicYear.start) + "_" + std::to_string(academicYear.start + 1) + "/";
	createDirectoryIfNotExists(academicYearFolderPath);
	return academicYearFolderPath;
}

string getAcademicYearFilePath(const AcademicYear& academicYear) {
	return getLoadedFilePath() + std::to_string(academicYear.start) + "_" + std::to_string(academicYear.start + 1) + ".csv";
}

string getSemesterFolderPath(const Semester& semester) {
	string academicYearFolderPath = getAcademicYearFolderPath(*(semester.ptrAcademicYear));
	string semesterFolderPath = academicYearFolderPath + semester.semesterID + "/";
	return semesterFolderPath;
}

string getSemesterFilePath(const Semester& semester) {
	return getLoadedFilePath() + semester.semesterID + ".csv";
}

string getCourseFolderPath(const Course& course) {
	string semesterFolderPath = getSemesterFolderPath(*(course.ptrSemester));
	string courseFolderPath = semesterFolderPath + course.ID + "/";
	return courseFolderPath;
}

string getCourseFilePath(const Course& course) {
	return getLoadedFilePath() + course.ID + ".csv";
}

string getInputListStudCourseFilePath(const Course& course) {
	string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_InputStud.csv";
}

string getOutputListStudCourseFilePath(const Course& course) {
	string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_OutputStud.csv";
}

string getInputScoreCourseFilePath(const Course& course) {
	string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_InputScore.csv";
}

string getOutputScoreStudCourseFilePath(const Course& course) {
	string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_OutputScore.csv";
}

//----------------------------------------------------------------------------------------------//

