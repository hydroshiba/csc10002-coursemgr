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

void createDirectoryIfNotExists(const std::string& dirPath)
{
	if (!std::filesystem::exists(dirPath)) {
		std::filesystem::create_directory(dirPath);
		std::cout << "Create directory " << dirPath << std::endl;
	}
}

std::string getListStaffFilePath(){
	return "Data/StaffList.csv";
}

std::string getListStudentFilePath(){
	return "Data/StudentList.csv";
}

std::string getListSchoolYearFilePath() {
	return "Data/SchoolYear/ListSchoolYear.csv";
}

std::string getListAcademicYearFilePath() {
	return "Data/AcademicYear/ListAcademicYear.csv";
}

std::string getSchoolYearFolderPath(const SchoolYear& schoolyear) {
	std::string schoolYearDirPath = "Data/SchoolYear/HCMUS_" + std::to_string(schoolyear.start) + "/";
	createDirectoryIfNotExists(schoolYearDirPath);
	return schoolYearDirPath;
}

std::string getInputSchoolYearFilePath(const SchoolYear& schoolyear) {
	std::string schoolYearFolderPath = getSchoolYearFolderPath(schoolyear);
	return schoolYearFolderPath + "HCMUS_" + std::to_string(schoolyear.start) + ".csv";
}

std::string getClassFolderPath(const Class& CLASS) {
	std::string schoolYearFolderPath = getSchoolYearFolderPath(*(CLASS.ptrSchoolYear));
	std::string classFolderPath = schoolYearFolderPath + CLASS.name + "/";
	createDirectoryIfNotExists(classFolderPath);
	return classFolderPath;
}

std::string getInputStudClassFilePath(const Class& CLASS) {
	std::string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + "_InputStud.csv";
}

std::string getDataStudClassFilePath(const Class& CLASS) {
	std::string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + "_StudData.csv";
}


std::string getInputScoreClassFilePath(const Class& CLASS) {
	std::string classFolderPath = getClassFolderPath(CLASS);
	return classFolderPath + CLASS.name + "_OutputScore.csv";
}

std::string getStudentFolderPath(const Student& student) {
	std::string classFolderPath = getClassFolderPath(*(student.ptrClass));
	std::string studentFolderPath = classFolderPath + "Students/" + student.ID + "/";
	createDirectoryIfNotExists(studentFolderPath);
	return studentFolderPath;
}

std::string getOutputScoreStudentFilePath(const Student& student) {
	std::string studentFolderPath = getStudentFolderPath(student);
	return studentFolderPath + student.ID + "_OutputScore.csv";
}

std::string getInputStandardIn4StudentFilePath(const Student& student) {
	std::string studentFolderPath = getStudentFolderPath(student);
	return studentFolderPath + student.ID + "_OutputStdIn4.csv";
}

std::string getAcademicYearFolderPath(const AcademicYear& academicYear) {
	std::string academicYearFolderPath = "Data/AcademicYear/" + std::to_string(academicYear.start) + "_" + std::to_string(academicYear.start + 1) + "/";
	createDirectoryIfNotExists(academicYearFolderPath);
	return academicYearFolderPath;
}

std::string getAcademicYearFilePath(const AcademicYear& academicYear) {
	std::string academicYearFolderPath = getAcademicYearFolderPath(academicYear);
	return academicYearFolderPath + std::to_string(academicYear.start) + "_" + std::to_string(academicYear.start + 1) + ".csv";
}

std::string getSemesterFolderPath(const Semester& semester) {
	std::string academicYearFolderPath = getAcademicYearFolderPath(*(semester.ptrAcademicYear));
	std::string semesterFolderPath = academicYearFolderPath + semester.semesterID + "/";
	return semesterFolderPath;
}

std::string getSemesterFilePath(const Semester& semester) {
	std::string semesterFolderPath = getSemesterFolderPath(semester);
	return semesterFolderPath + semester.semesterID + ".csv";
}

std::string getCourseFolderPath(const Course& course) {
	std::string semesterFolderPath = getSemesterFolderPath(*(course.ptrSemester));
	std::string courseFolderPath = semesterFolderPath + course.ID + "/";
	return courseFolderPath;
}

std::string getCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + ".csv";
}

std::string getInputListStudCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_InputStud.csv";
}

std::string getOutputListStudCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_OutputStud.csv";
}

std::string getInputScoreCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_InputScore.csv";
}

std::string getOutputScoreStudCourseFilePath(const Course& course) {
	std::string courseFolderPath = getCourseFolderPath(course);
	return courseFolderPath + course.ID + "_OutputScore.csv";
}

//----------------------------------------------------------------------------------------------//

